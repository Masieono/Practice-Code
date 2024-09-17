#include <iostream>

/*
    A loop within a loop. For, While, or Do While.

    This program draws a rectangle in the terminal
    based on user inputs of rows, columns, and
    character used.

    The nested for loop prints columns, while the
    outer for loop prints rows. Each row is printed
    top to bottom.
*/

using namespace std;

int main () {

    int rows;
    cout << "How many rows?\n";
    cin >> rows;

    int columns;
    cout << "How many columns?\n";
    cin >> columns;

    char symbol;
    cout << "Enter a symbol to use: \n";
    cin >> symbol;

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            cout << symbol;
        }
        cout << "\n";
    }
        




    return 0;
}