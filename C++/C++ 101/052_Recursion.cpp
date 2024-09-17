#include <iostream>

/*
    Recursion is a programming technique where a function
    calls itself from within. 

    Useful for searching algorithms

    Breaks down iteratively, or recursively
*/

using namespace std;

void iterative_walk(int steps)
{
    for(int i = 0; i < steps; i++)
    {
        cout << "You take a step" << endl;
    }
}

void recursive_walk(int steps) // takes more memory and processing time, but looks cleaner
{
    if (steps > 0)
    {
        cout << "You take a step" << endl;
        recursive_walk(steps - 1);
    }
}

int iterative_factorial(int num)
{
    int result = 1;

    for (int i = 1; i <= num; i++)
    {
        result = result * i;
    }
    return result;
}

int recursive_factorial(int num)
{
    if (num > 1)
    {
        return num * recursive_factorial(num - 1);
    }
    else 
    {
        return 1;
    }
}

int main () {

    iterative_walk(50);
    recursive_walk(50);

    cout << iterative_factorial(12) << endl;
    cout << recursive_factorial(12) << endl;

    return 0;
}