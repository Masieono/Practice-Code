#include <iostream>

/*

*/

using namespace std;

void PBV_swap(string x, string y)
{
    string temp;

    temp = x;
    x = y;
    y = temp;
}

void PBR_swap(string &x, string &y)
{
    string temp;

    temp = x;
    x = y;
    y = temp;
}

void print_values(string x, string y)
{
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << endl;
}

int main () {

    string x = "Koolaid";
    string y = "Water";

    print_values(x, y);

    cout << "Pass by value swap: " << endl;
    PBV_swap(x, y); // pass by value
    // this function makes copies of the arguments
    // and passes those values to the function.

    print_values(x, y);

    cout << "Pass by reference swap: " << endl;
    PBR_swap(x, y); // pass by reference
    // function takes the memory addresses of values
    // and operates directly on the values at that address
    // function must have & in it's parameters

    print_values(x, y);

    return 0;
}