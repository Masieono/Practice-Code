#include <iostream>

/*
    Type conversions transform data from one type to another.

    Implicit is automatic,
    Explicit conversion is when you precede a value with the new datatype.
*/

int main () {


    int x = 3.14;               // an integer will not hold decimal data
    double y = 3.14;            // a double will hold decimal data

    std::cout << x;             // we will not see the integer data
    std::cout << y;             // we will see the integer data

    std::cout << (double) x;    // even after casting to a double, there's no decimal data to see
    std::cout << (int) y;       // After casting to an integer, integer data is lost

    char a = 100;
    std::cout << a;             // outputs the ascii letter d 
    std::cout << (char) 100;    // outputs the ascii letter d

    int correct = 54;
    int questions = 71;
    double score = correct/(double) questions * 100;

    // type conversion to a double is necessary here, otherwise
    // the percentage calculation will be incorrect.

    std::cout << score << "%";

    return 0;
}