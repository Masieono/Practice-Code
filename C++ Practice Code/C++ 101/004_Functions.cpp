#include <stdio.h>


void birthday() {

    // We establish a "birthday" function (of type void, which returns nothing).
    // This function prints one verse of the birthday song.

    printf("\nHappy birthday to you!");
    printf("\nHappy birthday to you!");
    printf("\nHappy birthday dear BLANK,");
    printf("\nHappy birthday to you!");
}


int main() {

    // Instead of repeating multiple lines of code within our main function,
    // we simply call the function however many times we need to.
    // To call the function, type the name of the function followed by 
    // parentheses. These parentheses can hold values and arguments to be 
    // used by whatever function is being called.

    birthday();
    birthday();
    birthday();

    // Our main function sings happy birthday three times.

    return 0;
}