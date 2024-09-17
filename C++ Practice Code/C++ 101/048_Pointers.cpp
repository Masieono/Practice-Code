#include <iostream>

/*
    Pointer = a variable that stores a memory address
    of another variable. 

    Sometimes it is easier to work with a memory address

    & = 'address of' operator
    * = 'dereference' operator
*/

using namespace std;

int main () {

    string name = "Dooby";

    string *p_name = &name;
    // declare a pointer to the address of previous variable
    // notice that we are assigning the 'address of' the variable

    cout << *p_name << endl;
    // accessing the value that is at the given address.

    int age = 56;
    int *p_age = &age;

    cout << *p_age << endl;
    // same concept applies for type int

    string free_pizzas[5] = {"Pizza 1", "Pizza 2", "Pizza 3", "Pizza 4", "Pizza 5"};
    string *p_free_pizzas = free_pizzas;
    // the array is already a memory address

    cout << *p_free_pizzas << endl;

    return 0;
}