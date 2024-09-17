#include <iostream>

/*
    Loop that eases the traversal over
    an iterable data set
*/

using namespace std;

int main () {

    string students[] = {"Amir", "Bhetar", "Chonsin", "Derk", "Efrain", "Fhergie"};

    for (int i = 0; i < sizeof(students)/sizeof(string); i++) {
        cout << students[i] << endl;
    }
        // Will scan through the array. Has some more customizable
        // functionality when using the iterator.
        cout << "\n";

        // For each has less customizability, but will scan through
        // an array top to bottom. Takes less syntax as well.

    for(string student : students) {
        cout << student << endl;
    }

        cout << "\n";

    int grades[] = {93, 100, 84, 39, 40, 68, 72};

        // similar format to the for loop, but only two components.
        // (type variable_name : array_to_be_indexed)
    for(int grade : grades) {
        cout << grade << endl;
    }

    return 0;
}