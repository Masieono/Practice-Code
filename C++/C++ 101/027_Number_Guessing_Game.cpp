#include <iostream>
#include <ctime>

/*

*/

using namespace std;

int main () {

    srand(time(0));

    int num = rand() % 100 + 1;
    int guess;
    int tries = 0; 

    cout << "NUMBER GUESSER 9000\n";

    do {
        cout << "Enter a guess between 1 and 100: \n";
        cin >> guess;
        tries++;

        if (guess > num) {
            cout << "Too high!\n";
        }
        else if (guess < num) {
            cout << "Too low!\n";
        }
        else {
            cout << "Ding ding ding!\nIt only took you " << tries << " tries to get it right!\n";
        }

    } while (guess != num);

    cout << "BOTTOM TEXT 9000\n";

    return 0;
}