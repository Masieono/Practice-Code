#include <iostream>

/*

*/

using namespace std;

int main () {

    string foods[5]; 
    // won't be able to change the size of array while running
    int size = sizeof(foods)/sizeof(foods[0]);
    string temp;

    for(int i = 0; i < size; i++) {
        std::cout << "Enter a food you like: " << endl;
        std::cout << "Press 'Q' to quit" << endl;
        getline(cin, temp);

        if(temp == "Q" || temp == "q") {
            break;
        }
        else {
            foods[i] = temp;
        }

        std::cout << i + 1 << " of 5 foods entered." << endl;
    }

    std::cout << "You like the following foods: " << endl;
   
    for(int j = 0; !foods[j].empty(); j++) {

        std::cout << foods[j];
        std::cout << endl;
    }

    return 0;
}