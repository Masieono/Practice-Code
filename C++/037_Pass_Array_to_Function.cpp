#include <iostream>

/*

*/

using namespace std;

double get_total(double prices[], int array_size);

int main () {

    double prices[] = {83.99, 19.99, 52.15, 43.90, 5.99};
    int array_size = sizeof(prices) / sizeof(double);

    double total = get_total(prices, array_size);

    cout << "$" << total << " is the total" << endl;

    return 0;
}

/*
    External functions can't see how big an array is
    without help. This is why the size of the array
    is calculated in the main function, and the array
    and size are both passed to the external function
*/

double get_total(double prices[], int array_size) {
    double total = 0;

    for (int i = 0; i < array_size; i++) {
        total += prices[i]; 
    }
    return total;
}