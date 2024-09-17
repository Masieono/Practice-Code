/*
    Function prototypes ensure that calls to a function
    are made with the correct arguments.

    They are a function declaration, without a body, before main()

*/

#include <stdio.h>

void hello(char[], int); // this is the function declaration

int main() {

    char name[] = "Dooby";
    int age = 45;

    hello(name, age);

    return 0;
}

/*  
    Many compilers will not check function parameters, thus requiring function prototype
*/

void hello(char name[], int age) {
    printf("\nHello %s", name);
    printf("\nYou are %d years old", age);
}