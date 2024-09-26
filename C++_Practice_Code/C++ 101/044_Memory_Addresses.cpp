#include <iostream>

/*
    A location in memory where data is stored

    can be accessed with & (address-of operator)
*/

using namespace std;

int main () {

    string name = "Dooby";
    int age = 21;
    bool student = true;

    cout << &name << endl;
    cout << &age << endl;
    cout << &student << endl;

    /*
        ^ outputting the memory address of these variables, 
        not the values themselves.

        notice that the memory addresses are not equidistant.

        The boolean variable only consumes one byte of memory,
        thus takes up less space in memory.

        Running the program multiple times produces different
        hexadecimal values.
    */

    return 0;
}