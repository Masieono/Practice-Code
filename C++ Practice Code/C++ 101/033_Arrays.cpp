#include <iostream>

/*
    Array - data structure that can hold multiple values
    accessed by an index number
    "a variable that holds multiple values"

    Elements within arrays should all be of the same data type
*/

using namespace std;

int main () {

    string my_cars[] = {"Corvette", "Mustang", "Bronco"};
        //square brackets denote the use of an array

    cout << my_cars[0] << endl;
    cout << my_cars[1] << endl;
    cout << my_cars[2] << endl;
        //index starts at 0, different value is referenced each time

    string my_pets[2];
        // Array can be defined without preset values, 
        // but must state the number of values it holds.

    my_pets[0] = "Milo";
    my_pets[1] = "Zeppelin";

    double prices[] = {5.00, 7.50, 420.69, 19.99};
        // Array of type double

    cout << prices[0] << endl;
    cout << prices[1] << endl;
    cout << prices[2] << endl;
    cout << prices[3] << endl;

    return 0;
}