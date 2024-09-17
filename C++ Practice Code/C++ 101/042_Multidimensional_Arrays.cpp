#include <iostream>

/*
    Arrays that have two values for each element within array.
*/

using namespace std;

int main () {

    string cars[][3] = {{"Mustang", "Escape", "F-150"},
                        {"Corvette", "Equinox", "Silverado"},
                        {"Challenger", "Durango", "Ram 1500"},
                        {"Bus", "Beetle", "Jetta"}};
    // Set of square brackets are needed for each dimension within array
    // [x elements][y elements] x*y = total elements
    // when initializing, you at least need to specify column size.

    int cars_rows = sizeof(cars)/sizeof(cars[0]);
    // size of the total array / size of the row
    int cars_columns = sizeof(cars[0])/sizeof(cars[0][0]);
    // size of the row / size of the first unit in row

    cout << cars[0][0] << " ";
    cout << cars[0][1] << " ";
    cout << cars[0][2] << endl;

    cout << cars[1][0] << " ";
    cout << cars[1][1] << " ";
    cout << cars[1][2] << endl;

    cout << cars[2][0] << " ";
    cout << cars[2][1] << " ";
    cout << cars[2][2] << endl;

    cout << "\n\n";

    /*
        ^highly inneficient way to output an array, 
        the below for loop cycles through the array
        and prints exactly as stated above.
    */
    
    for(int i = 0; i < cars_rows; i++){
        for(int j = 0; j < cars_columns; j++){
            cout << cars[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    int number_cube[3][3][3] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
    };

    // still unclear about determining sizeof in this 
    // array, so the for loops are hard coded to size

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cout << number_cube[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}