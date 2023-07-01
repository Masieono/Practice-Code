#include <iostream>

/*
    Accepting user input from the c in requires >> 
    >> is the insertion operator.
    looks like going into something, whereas
    << is the extraction operator,
    looks like a megaphone shouting out something.

*/

using namespace std;

int main () {

    string name;        // must declare the expected input
    int age;

    cout << "What's your name? ";
    cin >> name;

    // insertion operator, we are having input set the string value

    cout << "Hello " << name << "\n";

    cout << "What's your age? ";
    cin >> age;

    // same method as before, this time with an int. Non-integer values
    // will return incorrect data, so make sure inputs are entered correctly,
    // or set up some kind of error checking for noninvalid inputs.

    cout << "You are " << age << " years old!" << "\n";

    cout << "what's your full name? ";
    getline(cin >> ws, name);

    // must use the getline command when expecting strings with
    // spaces in them. must also include the insertion operator
    // followed by the ws (whitespace) command in order to run
    // through the rest of your input prompts correctly.

    cout << "Your full name is " << name << "\n";

    // getline is more commonly used than the generic cin >>
    // is more applicable in most cases

    return 0;
}