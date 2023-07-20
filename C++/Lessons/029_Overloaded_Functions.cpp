#include <iostream>

/*
    Functions can share a name, as long as their parameters/
    arguments are different. We have two same-name functions 
    that bake a pizza, but one of them accepts a parameter

    A function name plus its parameters is a function signature,
    and all function signatures must be unique. 
*/

using namespace std;

void bake_pizza();
void bake_pizza(string topping1);
void bake_pizza(string topping1, string topping2);

int main () {

    bake_pizza();
    bake_pizza("anchovies");
    bake_pizza("mustard", "pineapple");

    return 0;
}

void bake_pizza() {
    cout << "You baked a pizza!\n";
}

void bake_pizza(string topping) {
    cout << "You baked a pizza with " << topping << " on it!\n";
}

void bake_pizza(string topping1, string topping2) {
    cout << "You baked a pizza with " << topping1 << "and " << topping2 << " on it!\n";
}