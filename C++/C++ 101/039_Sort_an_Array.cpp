#include <iostream>

/*
    "quick" bubble sort. Not the most optimized or the fastest,
    but a simple starter sort 
*/

using namespace std;

void ascending_sort(int array[], int size);
void descending_sort(int array[], int size);
void print_array(int array[], int size);

int main () {

    int array[] = {142, 309, 12, 653, 3958, 2942, 246, 24, 20424, 5867, 34, 9, 10098};
    int size = sizeof(array)/sizeof(array[0]);

    cout << "\nInput array data: " << endl;
    print_array(array, size);

    ascending_sort(array, size);

    cout << "\nSorted array data (ascending): " << endl;
    print_array(array, size);

    descending_sort(array, size);

    cout << "\nSorted array data (descending): " << endl;
    print_array(array, size);

    return 0;
}

void ascending_sort(int array[], int size) {
    
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] > array[j +1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j +1] = temp;
            }
        }
    }
}

void descending_sort(int array[], int size) {
    
    int temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(array[j] < array[j +1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j +1] = temp;
            }
        }
    }
}

void print_array(int array[], int size) {
    for (int k = 0; k < size; k++) {
        cout << array[k] << " ";
    }

}