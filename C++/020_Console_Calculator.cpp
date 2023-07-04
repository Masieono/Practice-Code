#include <iostream>

/*
    A simple calculator terminal application that 
    allows for the input of an operator, followed 
    by two numbers. The operator is used on the 
    variables in a switch case that prints the 
    result to the console.
*/

using namespace std;

int main () {

    char op;
    double num1;
    double num2;
    double result;

    cout << "LA CALCULADORA \n";
    cout << "Enter either + - * or / \n";
    cin >> op;

    cout << "Enter first number: \n";
    cin >> num1;

    cout << "Enter second number: \n";
    cin >> num2;

    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "sum = " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            cout << "difference = " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            cout << "product = " << result << "\n";
            break;
        case '/':
            result = num1 / num2;
            cout << "result = " << result << "\n";
            break;
        default:
            cout << "Sorry, not a valid operator";
            break;
    }

    return 0;
}