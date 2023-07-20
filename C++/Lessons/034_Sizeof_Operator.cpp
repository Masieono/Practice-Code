#include <iostream>

/*
    sizeof() will tell you the size in bytes of a variable,
    data type, class, structure, etc.
*/

using namespace std;

int main () {

    double gpa = 2.5;
    cout << gpa << " " << sizeof(gpa) << " bytes of data" << endl;
    
    string name = "Booby Dooby";
    cout << name << " " << sizeof(name) << " bytes of data" << endl;

    char grade = 'F';
    cout << grade << " " << sizeof(grade) << " bytes of data" << endl;

    bool student = true;
    cout << student << " " << sizeof(student) << " bytes of data" << endl;

    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    cout << sizeof(grades)/sizeof(char) << " grades within array" << endl;

    string students[] = {"Spongebob", "Patrick", "Squidward"};
    cout << sizeof(students)/sizeof(string) << " Students within array" << endl;

    return 0;
}