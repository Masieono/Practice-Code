#include <iostream>

/*
    Local variables are defined within a function or block {}
    There can be multiple local variables with the same name,
    but they must not be within the same block of code.

    Global variables are defined outside of all functions, are
    typically less secure, and pollute the global namespace.

    Functions will use local variables before they refer to global

*/

using namespace std;

int global_num = 3; //declared globally, anything can access/reference it

void print_num(int num);

int main () {

    int local_num = 1; // declared locally, must be handled with more care

    print_num(local_num);
    cout << global_num;

    return 0;
}

void print_num(int num) {
    cout << num << "\n";
}