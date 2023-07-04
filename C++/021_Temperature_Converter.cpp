#include <iostream>

/*
    Temperature conversion console program that
    converts temperatures from F to C and vice versa.
*/

using namespace std;

int main () {

    double temp;
    char unit;

    cout << "Temperature converter 9000 \n";
    cout << "F = fahrenheit \n";
    cout << "C = celcius \n";

    cout << "What unit would you like to convert to? \n";
    cin >> unit;

    if (unit == 'F' || 'f') {
        cout << "What is your temperature in celcius? \n";
        cin >> temp;

        temp = (1.8 * temp) + 32.0;
        cout << "Temperature is: " << temp << " degrees F \n";
    }
    else if (unit == 'C' || 'c') {
        cout << "What is your temperature in fahrenheit? \n";
        cin >> temp;

        temp = (temp - 32)/1.8;
        cout << "Temperature is: " << temp << " degrees C \n";
    }
    else {
        cout << "Sowwy, thats not a valid input :(( \n";
    }


    cout << "BOTTOM TEXT \n";

    return 0;
}