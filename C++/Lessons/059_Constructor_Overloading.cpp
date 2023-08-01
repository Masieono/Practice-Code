#include <iostream>

/*
    Multiple constructors with the same name, but different parameters

    Allows for varying arguments when instantiating an object.
*/

using namespace std;

class pizza {
    public:
        string topping1;
        string topping2;
        string topping3;
        string topping4;

    pizza()
    {

    }
    pizza(string topping1)
    {
        this->topping1 = topping1;
    }
    pizza(string topping1, string topping2)
    {
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
    pizza(string topping1, string topping2, string topping3)
    {
        this->topping1 = topping1;
        this->topping2 = topping2;
        this->topping3 = topping3;
    }
    pizza(string topping1, string topping2, string topping3, string topping4)
    {
        this->topping1 = topping1;
        this->topping2 = topping2;
        this->topping3 = topping3;
        this->topping4 = topping4;
    }
};


int main () {

    pizza blank_pizza(); // no toppings
    pizza pizza1("Pepperoni");
    pizza pizza2("Pepperoni", "Mushrooms");
    pizza pizza3("Pepperoni", "Mushroom", "Bell Pepper");
    pizza pizza4("Canadian Bacon", "Olives", "Red Pepper", "Mozzarella");

    // all constructed using the varying overloaded constructor of all the same name.

    return 0;
}