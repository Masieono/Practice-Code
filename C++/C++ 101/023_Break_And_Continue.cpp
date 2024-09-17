#include <iostream>

/*
    The break keyword will break out of a loop.

    Continue will skip the current iteration.
*/

using namespace std;

int main () {

    for (int i = 1; 1 <= 20; i++) {
        if (i == 13) {  // we want to skip over unlucky 13
            continue;
        }
        cout << i << "\n";
    }

    /*
        If we were to use the break keyword in the above for loop,
        terminal would output 1-12, and break out of loop before
        printing 13.

        Since we use the continue keyword, we successfully skip
        through the 13th iteration of the loop without printing.
    
    */

    return 0;
}