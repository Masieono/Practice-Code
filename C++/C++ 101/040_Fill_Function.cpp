#include <iostream>

/*
    Fill() fills a range of elements with a specified value
    fill(begin, end, value)

    In these tutorials, arrays have been manually implemented
    are have been relatively small in their contents. 

    Makes no sense to manually enter a high number of like values
    into an array when there is an easier method using fill()
*/

using namespace std;

int main () {

    const int SIZE = 99;
    string foods[SIZE];

    fill(foods, foods + SIZE / 3, "pizzatoni");
    fill(foods + (SIZE / 3), foods + (SIZE * 2 / 3), "Hambogs");
    fill(foods + (SIZE * 2 / 3), foods + SIZE, "Hotdurgers");

    for(string food : foods) {
        cout << food << " ";
    }

    return 0;
}