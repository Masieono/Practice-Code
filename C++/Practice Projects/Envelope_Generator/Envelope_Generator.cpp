#include <iostream>
#include <cmath>
#include <chrono>


/*
    AR / ASR envelope generator

    ramps from 0 to 1 in a set amount of time, 
    goes from 1 to 0 in a different set amount of time.

    offers slope control over the attack and release slope

    needs a way to show envelope, perhaps through terminal

    Also needs a way to source info about timing and slope,
    akin to the "lookat_knobs" function in old version


*/

using namespace std;

class envelope
{
    public:
        double attack_time;
        double decay_time;
        double sustain_level;
        double release_time;
        // basic components of an envelope

        double attack_slope_modifier;
        double decay_slope_modifier;
        double release_slope_modifier;
        // expected -10 to +10, effects the envelope amplitude

        double raw_amplitude;
        double envelope_amplitude;

        bool is_active;

        float fscale(float original_min, float original_max, float new_min, float new_max, float input_val, float curve)
        {
            float original_range = 0.0;
            float new_range = 0.0;
            float zero_ref_cur_val = 0.0;
            float normalized_cur_val = 0.0;
            float ranged_val = 0.0;
            bool inv_flag = 0;

            if (curve > 10) curve = 10;
            if (curve < -10) curve = -10;

            curve = curve * -0.1; // invert and scale. Positive numbers give more weight to high end on output
            curve = pow(10, curve); // convert linear scale to logarithmic exponent

            // check for out of range values
            if (input_val < original_min)
            {
                input_val = original_min;
            }
            if (input_val > original_max)
            {
                input_val = original_max;
            }

            original_range = original_max - original_min;

            if (new_max > new_min)
            {
                new_range = new_max - new_min;
            }
            else 
            {
                new_range = new_min - new_max;
                inv_flag = 1;
            }

            // normalize to 0-1 float
            zero_ref_cur_val = input_val - original_min;
            normalized_cur_val = zero_ref_cur_val / original_range;
            
            if (original_min > original_max)
            {
                return 0;
            }

            if (inv_flag == 0)
            {
                ranged_val = (pow(normalized_cur_val, curve) * new_range) + new_min;
            }
            else 
            {
                ranged_val = new_min - (pow(normalized_cur_val, curve) * new_range);
            }

            return ranged_val;
        }



};


int main () {

    /*
    
    
    
    
    
        print_envelope();
        print_values();
    */




    return 0;
}


enum envelope_phase {idle, attack, decay, sustain, release};


void check_knobs()
{
    switch(envelope_phase)
    {


    }


}


