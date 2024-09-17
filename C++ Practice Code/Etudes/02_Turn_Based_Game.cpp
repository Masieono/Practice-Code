#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

/*
    Demonstration of a turn-based terminal game. 

    The user defines how many turns the game will 
    last, and has the option to input a string. 
    
    The string is then printed to the console.

    After the final turn, the user is prompted to 
    play again,or quit out of the program.

    Nothing else happens.
*/

using namespace std;

void intro_sequence()
{
    cout << "\n\nWELCOME TO TURN BASED GAME 9000" << endl;
}

int get_num_turns()
{
    int num;
    
    do {
        cout << "Enter the number of turns for the game: " << endl;
        cin >> num;
    } while(num < 0 || num > 50);

    cin.ignore();

    return num;
}

string get_user_input(int turn_number)
{
    cout << "Turn number " << turn_number  << ": " << endl;
    cout << "Enter your input: " << endl;
    string input;
    getline(cin, input);

    return input;
}

void display_input(const string& input)
{
    cout << "You have entered: " << input << endl;
}

void display_result(int num_turns, const vector<string>& your_data)
{
    cout << "\n\nCongration, you have completed the turn-based game." << endl; 
    cout << "This game lasted " << your_data.size() << " turns." << endl;
    cout << "Here are the inputs you have entered: " << endl << endl;
    

    for(int i = 0; i < your_data.size(); i++)
    {
        cout << (i + 1) << ") " << your_data[i] << endl;    
    }

    cout << endl;
    cout << "Thank you for your time." << endl;
}

bool ask_to_play_again()
{
    char input;
    cout << endl;
    cout << "Would you like to play again? Y/N";
    cin >> input;
    return(input == 'Y' || input == 'y');  
}

void outro_sequence()
{
    cout << "Thanks for playing" << endl;
    cout << "TURN BASED GAME 9000" << endl;
}

int main () {

    intro_sequence();

    bool playing = true;
    while(playing)
    {
        int num_turns = get_num_turns();

        vector<string> your_data(num_turns);

        for(int i = 0; i < num_turns; i++)
        {
            string input = get_user_input(i + 1);
            
            your_data.at(i) = input;
            
            display_input(input);
        }

        display_result(num_turns, your_data);

        playing = ask_to_play_again();
    }
    outro_sequence();

    return 0;
}
