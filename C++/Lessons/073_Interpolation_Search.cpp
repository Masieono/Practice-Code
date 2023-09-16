#include <iostream>

/*
    Interpolation Search - 


    An improvement over the binary search,
    best used for "uniformly" distributed data.

    Guesses where a value might be based on probe
    results. If probe is incorrect, search area is
    narrowed, and new probe calculated.

    Average time complexity - O(log(log(n)))
    Worst time complexity - O(n)
*/

using std::cout;
using std::endl;

int interpolation_search(int array[], int array_size, int input)
{
    int high = array_size - 1;
    int low = 0;

    while (input >= array[low] && input <= array[high] && low <= high)
    {
        int probe = low + (high - low) * (input - array[low]) / (array[high] - array[low]);

        cout << probe << endl;

        if (array[probe] == input) return probe;
        else if (array[probe] < input) low = probe + 1;
        else high = probe - 1;
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
    cout << "Enter a number 0 - 10,000 to search for: " << endl;
    std::cin >> input;

    int index = interpolation_search(array, array_size, input);

    if (index != -1)
    {
        cout << "Number found at index " << index << endl; 
    }
    else {
        cout << "Number not found :(" << endl;
    }

    return 0;
}