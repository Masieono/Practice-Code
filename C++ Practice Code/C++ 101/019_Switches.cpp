#include <iostream>

/*
    A nice alternative to using excessive else if statements.
    checking for a few else if cases is fine, but if there are
    many cases that need to be checked, a switch case is better.

*/

using namespace std;

int main () {

    int month;

    cout << "Enter the month you were born in (1-12): ";
    cin >> month;

    switch(month) {
        case 1:
            cout << "You were born in January!";
            break;
        case 2:
            cout << "You were born in February!";
            break;
        case 3:
            cout << "You were born in March!";
            break;            
        case 4:
            cout << "You were born in April!";
            break;
        case 5:
            cout << "You were born in May!";
            break;
        case 6:
            cout << "You were born in June!";
            break;
        case 7:
            cout << "You were born in July!";
            break;
        case 8:
            cout << "You were born in August!";
            break;
        case 9:
            cout << "You were born in September!";
            break;
        case 10:
            cout << "You were born in October!";
            break;
        case 11:
            cout << "You were born in November!";
            break;
        case 12:
            cout << "You were born in December!";
            break;
        default: // if none of the cases match, the default case is run.
            cout << "Please input a valid number (1-12)";
    }

    return 0;
}