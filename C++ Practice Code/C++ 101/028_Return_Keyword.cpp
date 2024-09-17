#include <iostream>

/*
    Return keyword will return a value back to the 
    spot where you called the encompassing function 

    Functions should be of the same type of variable
    they return.

    Void functions return nothing.
    Int functions return an integer.
    String functions return a string, etc.   
*/

using namespace std;

double square(double length);
double cube(double length);
string concat_strings(string string1, string string2);

/*
    Function declarations must be made before the main function,
    or you could just write out the functions before main. It seems
    like an aesthetic choice to me.

    Declaring them and then specifying afterward seems to be more
    work, as you have to maintain the consistency of functions in
    three separate places of your code, rather than just two.

    But then you'd have to scroll past a lot of accessory functions
    just to see the main function and what it is doing.

    Do you want to type and maintain your file more, or do you want
    to hit that scroll wheel for .02 seconds longer. Same price.
*/

int main () {

    double length = 0.0;
    cout << "What is the length of one side of your square in centimeters?\n";
    cin >> length;

    double area = square(length);
    double volume = cube(length);

    cout << "Area is " << area << " centimeters squared\n";
    cout << "Volume of cube is " << volume << " cubic centimeters\n";

    string first_name;
    string last_name; 

    cout << "Gimme your first name: \n";
    cin >> first_name;

    cout << "Now gimme your last name: \n";
    cin >> last_name;

    string full_name = concat_strings(first_name, last_name);

    cout << "Your full name is " << full_name << "\n";

    return 0;
}

double square(double length) {
    return length * length;
}

double cube(double length) {
    return length * length * length;
}

string concat_strings(string string1, string string2) {
    return string1 + " " + string2;
}