#include <stdio.h>

/*
    A return statement is not only for the main function, 
    and accessory functions do not always have to be of 
    type void. In this example, the main function declares
    a value, which is then passed to the square function.
    The square function is of type double, rather than void.
    Instead of returning nothing, a double is returned.

*/

double square(double x) {

    return x * x;
}

int main() {

    double x = square(3.14);
    printf("%lf", x);

    return 0;
}