#include <iostream>
#include <cmath>

/*
    Useful math related functions within
    the standard library.

    Using the standard namespace, we can 
    call these functions without typing
    std:: every time we need to invoke them.

    Cmath library is added, giving us even 
    more math functions. 
*/

using namespace std;

void PrintValue (double z) {
    cout << z << "\n";
}

int main () {

    double x = 3.14;
    double y = 4;
    double z;

    z = max(x, y);      // find the highest value

    PrintValue(z);

    z = min(x, y);      // find the smallest value

    PrintValue(z);

    z = pow(x, y);      // raise the first arg to the power of second arg

    PrintValue(z);

    z = sqrt(9);        // square root of a number

    PrintValue(z);

    z = abs(-155);      // absolute value of a number

    PrintValue(z);

    z = round(x);       // rounds a number (up or down)

    PrintValue(z);

    z = ceil(x);        // rounds a number always up

    PrintValue(z);

    z = floor(x);       // rounds a number always down

    PrintValue(z);

    return 0;
}