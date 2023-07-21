#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

/*
    Terminal-based game that will play mastermind with you

    version one is limited to just guessing the computer's colors

    has the option to play the game with 3 to 6 pins being used
*/

using namespace std;

void intro_sequence() 
{
    cout << "\n\n\n";
    cout << "**********************" << endl;
    cout << "***** MASTERMIND *****" << endl;
    cout << "**********************" << endl;
    cout << "\n\n\n";
}

int set_num_pins()
{
    cout << "Select difficulty: \n" << endl;
    cout << "'E' for easy (three pins)" << endl;
    cout << "'N' for normal (four pins)" << endl;
    cout << "'H' for hard (five pins)" << endl;
    cout << "'X' for extra hard (six pins)" << endl;
    cout << endl;

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

void outro_sequence()
{
    cout << "\n\n\n";
    cout << "**********************" << endl;
    cout << "* THANKS FOR PLAYING *" << endl;
    cout << "**********************" << endl;
    cout << "***** MASTERMIND *****" << endl;
    cout << "**********************" << endl;
    cout << "\n\n\n";
}

// needs work, likely have to switch to vectors
void randomize_computer_colors(string colors[], int num_pins) {

    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<int> distribution(0, (sizeof(colors)/sizeof(colors[0])) - 1);

    string computer_colors[num_pins];

    for(int i = 0; i < num_pins; i++) {
        int temp = distribution(generator);
        computer_colors[i] = colors[temp];
    }
}

int main () {

    intro_sequence();
    int num_pins = set_num_pins();

    string colors[] = {"Black", "White", "Red", "Green", "Blue", "Yellow"};
    int num_colors = sizeof(colors)/sizeof(colors[0]);

    int num_turns;
    switch(num_pins) 
    {
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

    bool play_again = true;
    while(play_again) 
    {
        play_against_computer(num_pins, num_turns, num_colors);
        

        play_again = ask_to_play_again(); 
        //anything other than Y or y returns false, exiting the loop
    }

    outro_sequence();

    return 0;    
}

void play_against_computer(int num_pins, int num_turns, int num_colors) {

    //generate a random array of colors for the computer


    //run through each turn 
    for(int i = 0; i < num_turns; i++) {





    }


    
}


/*
    //at beginning of loop
    cout << "Type out colors separated by a space" <<endl;
    cout << "(blue red black yellow)" << endl;


    //each loop
    cout << "Turn number" << endl; //need to add turn number
    cout << "Enter your guess:" << endl; 

*/


void win_sequence(int num_guesses) //still needs work
{
    // auto end_time = chrono::high_resolution_clock::now();

    cout << "YOU WIN! YOU ARE THE" << endl;
    cout << "**** MASTERMIND ****\n" << endl;

    cout << "Number of guesses: " << endl; //need to insert num_guesses
    cout << "Total time: " << endl; //need to insert amount of time it took
}


void lose_sequence() //still needs work
{
    //auto end_time = chrono::high_resolution_clock::now();

    cout << "YOU LOSE! YOU AREN'T THE" << endl;
    cout << "****** MASTERMIND ******\n" << endl;

    cout << "Computer's colors: " << endl; //need to show computer generated colors
    cout << "Total time: " << endl; //need to insert amount of time it took
}


bool ask_to_play_again() {
    cout << "\nWould you like to play again? Type Y or N" << endl;
    char input;
    cin >> input;
    return (input == 'Y' || input == 'y');
}