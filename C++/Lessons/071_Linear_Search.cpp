#include <iostream>

/*
    Linear search iterates through a data structure 
    one element at a time.

    Runtime complexity - 0(n)
    Hence the *linear* in the title

    Pros - 
        Fast for small or medium size data sets
        Does not require sorting
        Useful when the data structure does not have random access

    Cons - 
        Not the best for large data sets
*/

using std::cout;
using std::endl;


int linear_search(int array[], int array_size, int value)
{

    for (int i = 0; i < array_size; i++)
    {
        if(array[i] == value)
        {
            return i;
        }
    }
    return -1;
}


int main () {

    int array[] = {11, 111, 1, 8, 1, 1, 68};
    int array_size = sizeof(array) / sizeof(int);

    int index = linear_search(array, array_size, 1);
    if(index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found within data" << endl;
    }

    return 0;
}