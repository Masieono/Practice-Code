#include <iostream>

/*

*/

using namespace std;

int main () {

    string students[] = {"Spengbab", "Baman", "Piderman", "Bomulus", "Bosephus"};

    cout << students[0] << "\n" << endl; // we can access elements one by one

    for (int i = 0; i < sizeof(students)/sizeof(string); i++) {
        // sizeof is used to calculate the number of array elements

        cout << students[i] << endl; 
        // index number is used to print a different name each iteration
    }

    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    for (int j = 0; j < sizeof(grades)/sizeof(char); j++) {
        cout << grades[j] << endl;
        // displays all contents of the grades array, even if you
        // change the number of contents in the array being used.
    }


    return 0;
}