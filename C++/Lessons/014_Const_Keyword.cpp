//  We are able to include code from anywhere else by 
// using the include syntax below. This includes the
// "iostream" header file from the C++ standard library.

#include <iostream>

using namespace std;

// the std namespace allows us to save time and space, 
// not having to type std:: numerous times.

int main() {

    // This is the main function. It is of type "int", 
    // which means the function will return an integer value.

    /*
        The const keyword specifies to the compiler that
        a variable's value is constant, and can not be modified.

        Trying to modify this variable will throw an error.
        This adds a layer of security when building a program.
    */

    const double PI = 3.14159;
    double radius = 10;
    double circumference = 2 * PI * radius;

    cout << circumference << "cm\n" ;


    // At the end of the main function, we return a value of 0,
    // this is generally used as a way to check that a program
    // has executed successfully and with no errors.

    return 0;
}

