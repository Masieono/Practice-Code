#include <iostream>

/*
    Inheritance = a class can receive attributes
    and methods from another class

    Children classes inherit from a parent class

    Helps to reuse similar code found within multiple classes
*/

using namespace std;

class animal {
    public:
        bool alive = true;

        void eat()
        {
            cout << "This animal is eating" << endl;
        }
};

class dog : public animal {
    public: 
        void bark()
        {
            cout << "Dog goes woof" << endl;
        }
};

class cat : public animal {
    public:
        void meow()
        {
            cout << "Cat goes meow" << endl;
        }
};

class shape {
    public: 
        double area;
        double volume;
};

class cube : public shape {
    public: 
        double side;

    cube(double side)
    {
        this->side = side;
        this->area = side * side * 6;
        this->volume = side * side * side;
    }
};

class sphere : public shape {
    public: 
        double radius;

    sphere(double radius)
    {
        this->radius = radius;
        this->area = 4 * 3.14159 * (radius * radius);
        this->volume = (4/3.0) * 3.14159 * (radius * radius);
    }

};

int main () {

    dog dog;
    
    cout << dog.alive << endl;
    dog.eat();
    dog.bark();

    cat cat;
    cout << cat.alive << endl;
    cat.eat();
    // cat.bark(); not available to this class
    cat.meow(); // meow is not available to the dog class either

    cube cube(10); 

    cout << "area: " << cube.area << endl;
    cout << "volume: " << cube.volume << endl;

    sphere sphere(10);

    cout << "area: " << sphere.area << endl;
    cout << "volume: " << sphere.volume << endl;


    return 0;
}