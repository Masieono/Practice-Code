/*
    A while loop will only run if it's condition is ever true. 
    The condition is checked before running the code.

    A do while loop runs a block of code, and then checks the while condition.
    The block of code is executed for as long as the condition remains true.
*/

#include <stdio.h>

int main() {

    int number = 0;
    int sum = 0;

    do {

        printf("Enter a number above zero: ");
        scanf("%d", &number);

        if(number > 0) {
            sum += number;
        }


    } while (number > 0);



    return 0;
}