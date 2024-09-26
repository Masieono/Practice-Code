#include <iostream>

/*
    Object = collection of attributes and methods

    Objects can have characteristics and perform actions.

    Can be used to mimic real-world items (phone, book, etc.)

    Created from a class which acts as a blueprint.
*/

using namespace std;

class human {
    public:
        string name;
        string occupation;
        int age;

        //^ characteristics of all members of the human class

        void eat()
        {
            cout << "This person is eating" << endl;
        }
        void sleep()
        {
            cout << "This person is sleeping" << endl;
        }
        void code()
        {
            cout << "This person is coding" << endl;
        }

        // ^ methods of all members of hte human class
};

class car {
    public :
        string make;
        string model;
        int year;
        string color;

        void accelerate()
        {
            cout << "GAS, GAS, GAS!" << endl;
        }
        void brake()
        {
            cout << "HIT THE BRAKE!" << endl;
        }
};

void print_human(human human)
{
    cout << human.name << ", age " << human.age << endl;
    cout << "Occupation: " << human.occupation << endl;
}

int main () {

    human human1;

    human1.name = "Rick";
    human1.occupation = "Scientist";
    human1.age = 70;

    print_human(human1);
    //similar to structs so far.

    human1.eat();
    human1.sleep();
    human1.code();

    human human2;
    human1.name = "Morty";
    human1.occupation = "Student";
    human1.age = 15;

    car car1;
    car1.make = "Ford";
    car1.model = "Bronco";
    car1.year = 1972;
    car1.color = "Blue";

    car1.accelerate();
    car1.brake();

    return 0;
}