#include <iostream>
#include <ctime>
#include <random>

/*
    This program rolls a d20, followed by 3 d6 rolls.

    Not truly random, but good enough for many applications.
*/

using namespace std;

void print_values(int d20, int d6_1, int d6_2, int d6_3)
{
    cout << "d20 roll: " << d20 << "\n";
    cout << "d6 number 1: " << d6_1 << "\n";
    cout << "d6 number 2: " << d6_2 << "\n";
    cout << "d6 number 3: " << d6_3 << "\n";
}

int main () {

    srand(time(NULL));

    int d20 = (rand() % 20) + 1;
    int d6_1 = (rand() % 6) + 1;
    int d6_2 = (rand() % 6) + 1;
    int d6_3 = (rand() % 6) + 1;

    print_values(d20, d6_1, d6_2, d6_3);

    d20 = (rand() % 20) + 1;
    d6_1 = (rand() % 6) + 1;
    d6_2 = (rand() % 6) + 1;
    d6_3 = (rand() % 6) + 1;

    print_values(d20, d6_1, d6_2, d6_3);

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> roll_d20(1, 20);
    uniform_int_distribution<int> roll_d6(1, 6);

    d20 = roll_d20(generator);
    d6_1 = roll_d6(generator);
    d6_2 = roll_d6(generator);
    d6_3 = roll_d6(generator);

    print_values(d20, d6_1, d6_2, d6_3);

    d20 = roll_d20(generator);
    d6_1 = roll_d6(generator);
    d6_2 = roll_d6(generator);
    d6_3 = roll_d6(generator);

    print_values(d20, d6_1, d6_2, d6_3);

    return 0;
}