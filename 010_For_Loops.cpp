#include <stdio.h>

int main() {

    /*
        For loops repeat a section of code a limited amount of times.
        There are three statements to establish a for loop:
        1 - Create an iterator
        2 - Define a condition for when to break out of the loop
        3 - increment the iterator
    */

   for(int i = 1; i <= 10; i++) {
        printf("%d\n", i);
    }

    /*
        The three statements are most traditionally seen as written above
        i is used to define the iterator,
        i is compared to an upper limit number,
        i is iterated by one.

        For loops do not have to always be in this configuration. 
        i does not have to initialize at 1, 
        i can compare to an external variable, not just a hardcoded number, 
        i can increment positively or negatively, and can also increment 
        by more than just one at a time
    */

   for(int i = 10; i >= 1; i--) {
        printf("%d\n", i);
   }

    /*
        i++     increment the variable by one
        i--     decrement the variable by one
        i+=n    increment the variable by n
        i-=n    decrement the variable by n
    */

   for(int i = 1; i <= 10; i+=2) {
        printf("%d\n", i);
   }

    return 0;
}