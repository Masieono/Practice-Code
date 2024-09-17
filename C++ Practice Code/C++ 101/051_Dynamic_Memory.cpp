#include <iostream>

/*
    Dynamic memory = memory that is allocated 
    after the program is compiled, and while
    the program is running.

    Memory is allocated on the heap rather than
    the stack using 'new' operator.

    Useful for when we don't know how much 
    memory we will need, such as accepting 
    user input that can vary wildly in size.
*/

using namespace std;

int main () {

    int *pNum = NULL;

    pNum = new int;

    *pNum = 21;

    cout << "address: " << pNum << endl;
    cout << "value: " << *pNum << endl;

    delete pNum;
    // expected to use delete after using new to 
    // free up memory and avoid memory leak.


    char *pGrades = NULL;

    int size;
    cout << "How many grades to enter in?" << endl;
    cin >> size;

    pGrades = new char[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter grade #" << i + 1 << ": ";
        cin >> pGrades[i]; 
    }

    for (int i = 0; i < size; i++)
    {
        cout << pGrades[i] << " ";
    }

    delete[] pGrades;

    return 0;
}