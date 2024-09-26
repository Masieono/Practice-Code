#include <stdio.h>
#include <string.h>

/*
    The while loop will repeat a section of code as long
    as a specific condition remains true.
*/

int main() {

    char name[25];

    printf("\nWhat is your name?: ");
    fgets(name, 25, stdin);
    name[strlen(name) - 1] = '\0';


    while(strlen(name) == 0) {
        printf("\nYou did not enter your name");
        printf("\nWhat is your name?: ");
        fgets(name, 25, stdin);
        name[strlen(name) -1] = '\0';

    }

    /*
        As long as their remains no name, the user will be prompted to enter a name
        if they enter a string of 0 length, they will get re-prompted to enter a name
    */

    printf("Hello %s", name);

    return 0;
}