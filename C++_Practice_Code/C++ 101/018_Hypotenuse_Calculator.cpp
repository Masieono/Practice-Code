#include <iostream>
#include <cmath>

/*
    Just need to code the pythagorean theorum.
    a^2 + b^2 = c^2

*/

using namespace std;

int main () {

    double a;   // side 1 of triangle
    double b;   // side 2 of triangle
    double c;   // hypotenuse

    cout << "Enter length of side A: \n";
    cin >> a;

    cout << "Enter length of side B: \n";
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));    // this is the magic right here

    cout << "The hypotenuse is " << c ;

    return 0;
}