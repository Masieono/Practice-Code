#include <iostream>
#include <ctime>
#include <chrono>

/*
    Terminal-based game that will play mastermind with you

    version one is limited to just guessing the computer's colors

    has the option to play the game with 3 to 6 pins being used
*/

using namespace std;

void intro_sequence() {
    cout << "\n\n\n\n";
    cout << "**********************" << endl;
    cout << "***** MASTERMIND *****" << endl;
    cout << "**********************" << endl;
    cout << "\n\n";
}

int set_num_pins() {

    cout << "Select difficulty: " << endl;
    cout << "'E' for easy (three pins)" << endl;
    cout << "'N' for normal (four pins)" << endl;
    cout << "'H' for hard (five pins)" << endl;
    cout << "'X' for extra hard (six pins)" << endl;

    char input;
    cin >> input;

    switch(input) {
        case 'E': return 3;
        case 'N': return 4;
        case 'H': return 5;
        case 'X': return 6;
        default: return 4;
    }

}

//still needs work
void win_sequence(int num_guesses) {

    cout << "YOU WIN! YOU ARE THE" << endl;
    cout << "**** MASTERMIND ****\n" << endl;


    cout << "Number of guesses: " << endl; //need to insert num_guesses
    cout << "Total time: " << endl; //need to insert amount of time it took

    cout << "Would you like to play again? Type Y or N" << endl;
    char input;
    cin >> input;
}

//still needs work
void lose_sequence() {

    cout << "YOU LOSE! YOU AREN'T THE" << endl;
    cout << "****** MASTERMIND ******\n" << endl;

    cout << "Computer's colors: " << endl; //need to show computer generated colors
    cout << "Total time: " << endl; //need to insert amount of time it took

    cout << "Would you like to play again? Type Y or N" << endl;
    char input;
    cin >> input;

    // offer a "play again" feature
}

//still needs work
int generate_computer_colors(int random_values[], int num_colors) {

    /*
        function that will generate random series of colors
    */
   
    srand(time(NULL));    

    for(int i = 0; i < num_colors; i++) {
        random_values[i] = rand() % num_colors;
    }
    
}

//still needs work
bool play_against_computer(int num_turns) {


    //this is the mode where a player guesses for num_turns
    
        // run the generate_computer_colors function to get computer colors

        // time code starts when the first guess is entered

        // loop through guesses where a user input is compared to the computer array

        // run a function to check if pins are correct color in correct spot, returns a number of "black" pins

        // run a function to check if pins are correct color in incorrect spot, returns a number of "white" pins

        // cout the turn number, black, and white pins.

        // if there is a complete match, run the win condition function and ask to play again.

        // if max guesses is reached without an exact match, run the lose function and ask to play again.



    //return true for a win, false for a lose
}


int main () {

    intro_sequence();
    int num_pins = set_num_pins();

    string colors[] = {"Black", "White", "Red", "Green", "Blue", "Yellow"};
    int num_colors = sizeof(colors)/sizeof(colors[0]);

    int num_turns;
    switch(num_pins) {
        case 'N': 
            num_turns = 10;
            break;
        case 'H': 
            num_turns = 15;
            break;
        case 'X':
            num_turns = 20;
            break;
        default:
            num_turns = 5;
            break;
    }



    return 0;    
}
/*
    //at beginning of loop
    cout << "Type out colors separated by a space" <<endl;
    cout << "(blue red black yellow)" << endl;


    //each loop
    cout << "Turn number" << endl; //need to add turn number
    cout << "Enter your guess:" << endl; 

*/