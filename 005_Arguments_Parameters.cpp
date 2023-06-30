#include <stdio.h>

/*
    We have a similar setup to the previous tutorial. 
    A birthday function that gets called within the main function.
    This time, we have declared some variables within main that
    are sent to and used by our birthday function.
    The birthday function must know what types of variables 
    will be passed to it.
*/

void birthday(char x[], int y) {

    /*
        We have declared variables representing name (as x)
        and age (as y). Variable names only need to match
        within the function.
    */  

    printf("\nHappy birthday dear %s!", x);
    printf("\nYou are %d years old!", y);
}

/*
    Within the birthday function, format specifiers are used 
    to insert program data into a print statement. 
    %s for type char or string, and %d for an integer.
    Both are followed by the variable name after a comma.
*/

int main() {

    /*
        Name and age are both declared within the main function.
        Both variables are then sent to the birthday function.
        Birthday function is void, so nothing is returned back
        to the main function.
    */

    char name[] = "Tom Boolery";
    int age = 46;

    birthday(name, age);

    return 0;
}

/*
    When passing arguments to a function, their type must be declared in the 
    recieving function. 
    They must be sent to to the function in the same order they are declared.

    Arguments are what you send a function.
    Parameters are what a function expects when it is invoked.
*/