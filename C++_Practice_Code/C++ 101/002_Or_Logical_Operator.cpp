#include <stdio.h>
#include <stdbool.h>

int main() {

    // logical operators = || (or) checks if at least one condition is true

    float temp = 25;

    if(temp <= 0 || temp >= 30) {
        printf("\nThe weather is bad!");
    }
    else{
        printf("\nThe weather is good!");
    }

    // the "\n" creates a line break within the output

    return 0;
}