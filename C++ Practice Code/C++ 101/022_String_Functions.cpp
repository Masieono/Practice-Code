#include <iostream>

/*
    Previously had string functions that were a
    part of the C library, but these are even 
    better, as they are part of the C++ library.
*/

using namespace std;

int main () {

    string name;

    cout << "Enter your name: \n";
    getline(cin, name);

    if (name.length() > 12) {
        cout << "Your name is too long :(\n";
    }
        // the length function will calculate the length of the string
    else if (name.empty()) {
        cout << "You didn't enter your name :(";    
    }
        // the empty function will return true if the string has no characters.
    else {
        cout << "Wassup " << name;
    }

    name.clear();   // will clear the string of previous contents.
    name.append("@gmail.com");  // will add to the end of your string.
    name.at(0);     // will return the character at the specified index.
    name.insert(0, "insert");   // will insert into your string at a specified index
    name.find(' '); // will find the position of the first space.
    name.erase(0, 3); // will eliminate a portion of the string, start index - ending index noninclusive.

    return 0;
}