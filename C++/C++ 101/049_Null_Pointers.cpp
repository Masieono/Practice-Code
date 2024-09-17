#include <iostream>

/*
    Null value - a special value that means 'no value'

    When a pointer is holding a null value, that pointer
    is not pointing to anything at all.

    nullptr = keyword represents a null pointer literal

    nullptrs are helpful when determining if an address
    was successfully assigned to a pointer

*/

using namespace std;

int main () {

    int *pointer = nullptr;
    int x = 123;

    pointer = &x;
    // commenting out the above line will
    // toggle the below if/else statement

    if(pointer == nullptr)
    {
        cout << "address was not assigned";
    }
    else
    {
        cout << "address was assigned";
        cout << *pointer;
    }

    return 0;
}