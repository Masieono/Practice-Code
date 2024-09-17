#include <iostream>

/*
    enums = user defined data type that consists of 
    paired named-integer constants.

    great if you have a set of potential options.
*/

using namespace std;

enum Day {sunday = 0, monday, tuesday, wednesday, thursday, friday, saturday};
// implicitly numbered like an array, but can be explicitly numbered as desired

enum Envelope {attack_phase, decay_phase, sustain_phase, release_phase};

int main () {

    Day today = sunday;

    switch(today)
    {
        case sunday: 
            cout << "It is Sunday!" << endl;
            break;
        case monday:
            cout << "It is Monday!" << endl;
            break;
        case tuesday:
            cout << "It is Tuesday!" << endl;
            break;
        case wednesday:
            cout << "It is Wednesday!" << endl;
            break;
        case thursday:
            cout << "It is Thursday!" << endl;
            break;
        case friday:
            cout << "It is Friday!" << endl;
            break;
        case saturday:
            cout << "It is Saturday!" << endl;
            break;
    }



    return 0;
}