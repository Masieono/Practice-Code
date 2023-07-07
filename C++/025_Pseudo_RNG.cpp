#include <iostream>
#include <ctime>

/*
    This program rolls a d20, followed by 3 d6 rolls.

    Not truly random, but good enough for many applications.
*/

using namespace std;

int main () {

    srand(time(NULL));

    int d20 = (rand() % 20) + 1;

    cout << "d20 roll: " << d20 << "\n";

    int d6_1 = (rand() % 6) + 1;
    int d6_2 = (rand() % 6) + 1;
    int d6_3 = (rand() % 6) + 1;

    cout << "d6 number 1: " << d6_1 << "\n";
    cout << "d6 number 2: " << d6_2 << "\n";
    cout << "d6 number 3: " << d6_3 << "\n";

    return 0;
}