#include <iostream>

/*
    abstraction = hiding unnecessary data from outside a class

    getter = function that makes a private attribute READABLE
    setter = function that makes a private attribute WRITEABLE
*/

using namespace std;

class stove {
    private:
        int temperature = 0;

    public:

        stove(int temperature)
        {
            set_temperature(temperature);
        }
        
        int get_temperature()
        {
            return temperature;
        }
        void set_temperature(int temperature)
        {
            if(temperature < 0) 
            {
                this->temperature = 0;
            }
            else if(temperature >= 10) 
            {
                this->temperature = 10;
            }
            else
            {
                this->temperature = temperature;
            }
        }
};

int main () {

    stove stove(0);

    stove.set_temperature(175);
    
    cout << "The stove temperature is " << stove.get_temperature() << endl;


    return 0;
}