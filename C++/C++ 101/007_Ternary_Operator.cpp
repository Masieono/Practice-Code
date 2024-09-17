/*
    The ternary, or conditional operator, is a quick lil
    if/else when assigning or returning a value. It checks
    a specific condition and returns different values for
    true and false.

    (condition) ? value if true : value if false
*/

#include <stdio.h>

int find_max(int x, int y) {

    return (x > y) ? x : y;
}


int main() {

    int max = find_max(3, 4);
    printf("%d", max);

    return 0;
}