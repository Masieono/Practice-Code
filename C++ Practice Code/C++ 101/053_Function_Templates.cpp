#include <iostream>

/*
    Describes what a function looks like.
    Can be used to generate as many overloaded
    functions as needed, each using different data types
*/

using namespace std;

int max (int x, int y)
{
    return (x > y) ? x : y;
}
double max (double x, double y)
{
    return (x > y) ? x : y;
}
char max (char x, char y)
{
    return (x > y) ? x : y;
}
// above method can be tedious when needing
// to use the same method function for many
// different data types.


template <typename T, typename U>
auto template_max(T x, U y)
{
    return (x > y) ? x : y;
}
// above method does all data types in one function
// specifically comparing two different data types

int main () {

    cout << max(1, 2);
    // works as intended becuase integers are passed in

    cout << max(1.1, 2.1);
    // does not work as intended, floats/doubles are passed in

    return 0;
}