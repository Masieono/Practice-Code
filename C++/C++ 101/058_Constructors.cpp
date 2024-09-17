#include <iostream>

/*
    Constructor = special method within a 
    class that is automatically called when 
    an object is instantiated.

    Useful for assigning values to attributes 
    as arguments.
*/

using namespace std;

class student {
    public: 
        string name;
        int age;
        double gpa;

    student(string name, int age, double gpa) 
    {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

class car {
    public: 
        string make;
        string model;
        int year;
        string color;

    car(string make, string model, int year, string color)
    {
        this->make = make;
        this->model = model;
        this->year = year;
        this->color = color;
    }
};

int main () {

    student student1("Spongebob", 25, 3.2);
    student student2("Patrick", 24, 2.6);
    student student3("Sandy", 24, 4.0);

    car car1("Ford", "Bronco", 1968, "Blue");
    car car2("Ford", "Mustang", 2023, "Red");

    return 0;
}