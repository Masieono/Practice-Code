#include <iostream>

/*

*/

using namespace std;

int search_array(int array[], int size, int element) {

    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

int main () {

    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    int index;
    int my_number;

    cout << "Enter your search number: " << endl;
    cin >> my_number;

    index = search_array(numbers, size, my_number);

    if (index != -1) {
        cout << my_number << " is indexed at " << index << endl;
    }
    else {
        cout << my_number << " was not found" << endl;
    }

    return 0;
}