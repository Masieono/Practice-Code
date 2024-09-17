#include <iostream>

/*

*/

using namespace std;

struct car
{
    string make;
    string model;
    int year;
    string color;
};

void print_car(car &car)
{
    cout << car.make << endl;
    cout << car.model << endl;
    cout << car.year << endl;
    cout << car.color << endl;
}

void paint_car(car &car, string color)
{
    car.color = color;
}

int main () {

    car car1;
    car car2;

    car1.make = "Ford";
    car1.model = "Bronco";
    car1.year = 1975;
    car1.color = "Black";

    car2.make = "Volkswagon";
    car2.model = "Bus";
    car2.year = 1968;
    car2.color = "Green";

    paint_car(car1, "Silver");
    paint_car(car2, "Gold");

    print_car(car1);
    print_car(car2);


    return 0;
}