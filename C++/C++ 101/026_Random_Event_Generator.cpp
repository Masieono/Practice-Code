#include <iostream>
#include <ctime>

/*
    A continuation of previous RNG lesson.

    Switch is setup to generate different events
    based on a random number.
*/

using namespace std;

int main () {

    srand(time(0)); // must seed the RNG machine for random to blossom

    int rand_num = (rand() % 5) + 1;

    switch (rand_num) {
        case 1:
            cout << "You win a banana peel :O\n";
            break;
        case 2:
            cout << "You win a pair of pants :(\n";
            break;
        case 3:
            cout << "You win a spare tire :/\n";
            break;
        case 4:
            cout << "You win a bongo drums :|\n";
            break;
        case 5:
            cout << "You win a new frying pan! :)\n";
            break;
        default:

            break;
    }

    return 0;
}