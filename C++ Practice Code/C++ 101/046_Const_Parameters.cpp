#include <iostream>

/*
    const parameter = makes a parameter effectively read-only

    code is more secure and conveys intent in a code

    useful for references and pointers
*/

using namespace std;

void print_info(const string &name, const int &age)
{
    // name = "Zooby";
    // age = 12;

    /*
    these will throw an error, as the parameter 
    definition makes these values unchangeable  
    */
    
    cout << name << endl;
    cout << age << endl;
    cout << endl;
}

int main () 
{
    string name = "Booby";
    int age = 56;

    print_info(name, age);

    return 0;
}