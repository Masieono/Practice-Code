#include <iostream>

/*
    Binary search - Finds the position of a target value
    within a *sorted* array. Half of the array is eliminated
    during each step.

    Time complexity - O(log n)
    Becomes more efficient as n increases.

    Binary search requires the data structure to be sorted

    Basic process - 
        Start in the middle of the data structure, 
        check if the search value is higher or lower,
        eliminate the irrelevant half of structure

        With the remaining half of the data structure,
        start in the middle and compare the search value,
        eliminate the irrelevant half of structure

        Repeat until the value is found.
*/

using std::cout;
using std::endl;

int binary_search(int array[], int array_size, int input)
{
    int low = 0;
    int high = array_size - 1;

    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        int value = array[middle];

        if(value < input) low = middle + 1;
        else if (value > input) high = middle - 1;
        else return middle;
    }

    return -1;
}


int main () {

    int array[10000];
    int array_size = sizeof(array) / sizeof(int);

    for (int i = 0; i < array_size; i++)
    {
        array[i] = i;
    }

    int input;
    cout << "Enter a number 0-10,000 to find" << endl;
    std::cin >> input;

    int index = binary_search(array, array_size, input);

    if (index != -1)
    {
        cout << input << " was found at " << index << endl;
    }
    else {
        cout << input << " was not found." << endl;
    }


    return 0;
}