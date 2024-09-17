#include <stdio.h>
#include <stdbool.h>

int main() {

    // logical operators = ! (not) reverses the state of a condition

    bool sunny = true;

    // true = 1, false = 0
    // only mentioning the boolean will default to it's initialized state, 
    // so in this instance, we are checking to see if the boolean is in
    // the reverse of the initialized state. 

    if(!sunny){
        printf("\nIt's cloudy outside!");
    }
    else{
        printf("\nIt's sunny outside!");
    }

    return 0;
}