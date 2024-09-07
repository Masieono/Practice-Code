#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <MapFloat.h>

int atkpot = A0;          //controls length of attack
int decpot = A1;          //controls length of decay
int atkSlopePot = A4;     //controls the attack curve
int decSlopePot = A3;     //controls the decay curve
int glitVal = A2;         //piezo sensor
  
bool env_on;              //true when the envelope is active
bool attackState;         //only true during the attack slope
bool decayState;          //only true during the decay slope
  
float atkSlopeMod;        //modifier for scaling the attack curve
float decSlopeMod;        //modifier for scaling the decay curve
float envAmp = 0.0;       //quotient that approaches to 1 in attack phase and approaches 0 in decay phase
float scaledAmp = 0.0;    //envelope scaled according to attack and decay slope modifiers

unsigned long trigtime;  //time since the program was initiated
unsigned long atkTime;    //total time of attack phase
unsigned long decTime;    //total time of decay phase

int env_phase;            //0 is idle, 1 is attack, 2 is decay

void setup() {
  pinMode(atkpot, INPUT);
  pinMode(decpot, INPUT);
  pinMode(glitVal, INPUT);
  pinMode(atkSlopePot, INPUT);
  pinMode(decSlopePot, INPUT);
  Serial.begin(9600);
  //device should read all four potentiometers and piezo as inputs to the microcontroller

}

void loop() {

  float init_env = 1.0;                     //initial setting of envelope
  
  unsigned long envLifetime;                //total time an envelope has been active
  unsigned long trigtime;        //time in which a trigger is detected
  
  lookat_knobs(env_phase);                  //scan either attack or decay knobs, depending on the envelope phase
  
  int piezo = analogRead(glitVal);          //reads and rounds off the reading from the piezo sensor
    if (piezo < 25) piezo = 0;              
                                            
    if (piezo > 24){                        //when piezo senses a high enough trigger value, the envelope starts
      env_on = true;
      attackState = true;
      decayState = false;
      env_phase = 1;
      envLifetime = 1;
      init_env = 1.0;
      trigtime = millis();
    }
  
          /*
          if (envLifetime <= atkTime){  
            envAmp = (envLifetime / atkTime) * init_env;
          //scales from 0 to 1 as the envelope reaches the end of the attack phase
    
          float scaledAmp = fscale(0, 1, 0, 4095, envAmp, atkSlopeMod);
            if (scaledAmp > 4094.99) scaledAmp = 4095;
          // Calculates the envelope value and adjusts the curve depending on the slope modifier 
          
    
          if (envLifetime > atkTime){
            attackState = false;
            decayState = true;
            env_phase = 2;
          //once the envelope reaches the end of attack, envelope transitions into decay 
          
            envAmp = (envLifetime - atkTime) / decTime;
          //scales from 0 to 1 as the envelope reaches the end of the decay phase
    
          float scaledAmp = fscale(1, 0, 0, 4095, envAmp, decSlopeMod);
            if (scaledAmp < 0.001) scaledAmp = 0;
          }
          //calculates the envelope value and adjusts the curve depending on the slope modifier

          else {
            envAmp = 0;
            env_on = false;
            envLifetime = 0;
            env_phase = 0; 
            attackState = false;
            decayState = false;
          }    
          //once the envelope ticks past the total time set by attack and decay, parameters are reset.
        }

*/


Serial.print("Piezo: ");
Serial.print(piezo);
Serial.print(" ");

Serial.print("Envelope Active: ");
Serial.print(env_on);
Serial.print(" ");

Serial.print("Envelope Phase: ");
Serial.print(env_phase);
Serial.print(" ");

Serial.print("Lifetime: ");
Serial.print(envLifetime);
Serial.print(" ");

Serial.print("Amplitude ");
Serial.print(envAmp);
Serial.println(" ");

    //print_values(envLifetime, env_on, env_phase, piezo, scaledAmp, atkTime, atkSlopeMod, decTime, decSlopeMod);
    
}

void lookat_knobs(int env_phase){
  switch (env_phase){
    case 0: 
      break;
      //idle phase, home base where everything is initialized
    
    case 1:
     unsigned long atkMod = map(analogRead(atkpot), 1024, 0, 0, 100);
       if (atkMod < 50) atkTime = map(atkMod, 0, 50, 0, 1000);
       else if (atkMod > 49) atkTime = map(atkMod, 50, 100, 1000, 10000);  
     // Reads potentiometer value, scales it to total attack time in ms

    float atkSlopeMod = mapFloat(analogRead(atkSlopePot), 1024.0, 0.0, -10.0, 10.0);
      if (atkSlopeMod > -.05 && atkSlopeMod < .05) atkSlopeMod = 0;
      if (atkSlopeMod > 9.90) atkSlopeMod = 10.00;
      if (atkSlopeMod < -9.90) atkSlopeMod = -10.00;
     // rounds off the attack slope knob reading and maps it to -10 to 10  

Serial.print("T_atk: ");
Serial.print(atkTime);
Serial.print(" ");
Serial.print("Mod: ");
Serial.print(atkSlopeMod);
Serial.print(" ");

      break;
    
    case 2:
      unsigned long decMod = map(analogRead(decpot), 1024, 0, 0, 100);
        if (decMod < 50) {decTime = map(decMod, 0, 50, 1, 1000);}
        if (decMod > 49) {decTime = map(decMod, 50, 100, 1000, 10000);}    
      // Reads potentiometer value, scales it to total decay time in ms
  
      float decSlopeMod = mapFloat(analogRead(decSlopePot), 1024.0, 0.0, -10.0, 10.0);
        if (decSlopeMod > -.05 && decSlopeMod < .05) atkSlopeMod = 0;
        if (decSlopeMod > 9.90) decSlopeMod = 10.00;
        if (decSlopeMod < -9.90) decSlopeMod = -10.00;
      // rounds off the attack slope knob reading and maps it to -10 to 10

Serial.print("T_dec: ");
Serial.print(decTime);
Serial.print(decSlopeMod);
Serial.print(" ");
      //not sure if these should be returned, or if you can return multiple values

      break;     
    }
}

void print_values(bool env_on, unsigned long envLifetime, int env_phase, int glitTouch,float scaledAmp, 
                    int atkTime,float atkSlopeMod,int decTime,float decSlopeMod){
  
      Serial.print("Trig: ");
      Serial.print(glitTouch);
      Serial.print(" ");
      // reads and prints the piezo sensor value
      Serial.print("Env: ");
      Serial.print(env_on);
      Serial.print(" ");
      // is the envelope on
      Serial.print("Phase: ");
      Serial.print(env_phase);
      Serial.print(" ");
      // what phase is the envelope in    
      Serial.print("Lifetime: ");
      Serial.print(envLifetime);
      Serial.print(" ");
      // how long has the envelope been going
      Serial.print("Envelope:");
      Serial.print(scaledAmp);
      Serial.print(" ");
      // prints the envelope value to be sent to DAC 
      Serial.print("t_atk ");
      Serial.print(atkTime);
      Serial.print(" ");
      // attack time in milliseconds
      Serial.print("curve:");
      Serial.print(atkSlopeMod);
      Serial.print(" ");
      // prints the modifier for the attack curve
      Serial.print("t_dec ");
      Serial.print(decTime);
      Serial.print(" ");
      // decay time in milliseconds
      Serial.print("curve:");
      Serial.print(decSlopeMod);
      Serial.println(" ");
      // prints the modifier for the decay slope curve
  }

float fscale( float originalMin, float originalMax, float newBegin, float newEnd, float inputValue, float curve){
        
        float OriginalRange = 0;
        float NewRange = 0;
        float zeroRefCurVal = 0;
        float normalizedCurVal = 0;
        float rangedValue = 0;
        boolean invFlag = 0;
  
  if (curve > 10) curve = 10;
  if (curve < -10) curve = -10;

curve = (curve * -.1) ; // - invert and scale - this seems more intuitive - postive numbers give more weight to high end on output
curve = pow(10, curve); // convert linear scale into lograthimic exponent for other pow function

// Check for out of range inputValues
if (inputValue < originalMin) {
inputValue = originalMin;
}
if (inputValue > originalMax) {
inputValue = originalMax;
}

// Zero Refference the values
OriginalRange = originalMax - originalMin;

if (newEnd > newBegin){
NewRange = newEnd - newBegin;
}
else
{
NewRange = newBegin - newEnd;
invFlag = 1;
}

zeroRefCurVal = inputValue - originalMin;
normalizedCurVal = zeroRefCurVal / OriginalRange; // normalize to 0 - 1 float

// Check for originalMin > originalMax - the math for all other cases i.e. negative numbers seems to work out fine
if (originalMin > originalMax ) {
return 0;
}

if (invFlag == 0){
rangedValue = (pow(normalizedCurVal, curve) * NewRange) + newBegin;
}
else // invert the ranges
{ 
rangedValue = newBegin - (pow(normalizedCurVal, curve) * NewRange);
}
return rangedValue;
;
}