#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <string>

/*
    Terminal-based game that will play mastermind with you

    version one is limited to just guessing the computer's colors

    has the option to play the game with 3 to 6 pins being used
*/

using namespace std;

void intro_sequence() 
{
    cout << "\n";
    cout << "**********************" << endl;
    cout << "***** MASTERMIND *****" << endl;
    cout << "**********************" << endl;
    cout << "\n";
}

int set_num_pins()
{
    cout << "Select difficulty: \n" << endl;
    cout << "'E' for easy (three pins)" << endl;
    cout << "'N' for normal (four pins)" << endl;
    cout << "'H' for hard (five pins)" << endl;
    cout << "'X' for extra hard (six pins)" << endl;
    cout << endl;

    cout << "Input: ";
    char input;
    cin >> input; 
    
    switch(input) {
        case 'E': return 3;
        case 'e': return 3;
        case 'N': return 4;
        case 'n': return 4;
        case 'H': return 5;
        case 'h': return 5;        
        case 'X': return 6;
        case 'x': return 6;
        default: return 4;
    }
}

int how_many_turns(int num_pins) {
    switch (num_pins) {
        case 3: return 10;
        case 4: return 10;
        case 5: return 15;
        case 6: return 20;
        default: return 10;
    }
}

vector<string> get_player_guess(int num_pins)
{
    vector<string> guess; // the final product in correct data type

    // cin.ignore();
    cout << "Type out colors separated by a space: ";
    string input;
    getline(cin, input); // the full line guess (green red black yellow)

    istringstream iss(input);
    string element;

    while (iss >> element)
    {
        transform(element.begin(), element.end(), element.begin(), ::tolower);
        guess.push_back(element);
    }

    return guess;
}

int check_for_black_pins(const vector<string>& guess, const vector<string>& computer_colors)
{
    int black_pins = 0;

    for(int i = 0; i < computer_colors.size(); i++)
    {
        if(guess[i] == computer_colors[i])
        {
            black_pins++;
        }
    }
    return black_pins;
}

int check_for_white_pins(const vector<string>& guess, const vector<string>& computer_colors)
{
    int white_pins = 0;
    vector<bool> scanned(computer_colors.size(), false);

    for(int i = 0; i < guess.size(); i++) //scan through guess
    {
        if (guess[i] == computer_colors[i]) //weed out black pins
        {
            continue;
        }
    
        for(int j = 0; j < computer_colors.size(); j++) //scan through computer colors
        {
            if(!scanned[j] && guess[i] == computer_colors[j] && guess[j] != computer_colors[j]) //check for previously found white pins
            {
                white_pins++;
                scanned[j] = true;
                break;
            }
        }
    }

    return white_pins;
}

vector<string> convert_player_guess(const vector<string>& colors, const vector<string>& guess, int num_pins)
{
    vector<string> abbr_colors = {"blk", "wht", "red", "grn", "blu", "ylo"};

    vector<string> converted_guess;

    for (const string& guess_color : guess)
    {
        bool color_found = false;

        for (int i = 0; i < colors.size(); i++)
        {
            if(guess_color == colors[i])
            {
                converted_guess.push_back(abbr_colors[i]);
                color_found = true;
                break;
            }
        }

        if(!color_found)
        {
            converted_guess.push_back(guess_color.substr(0, 3));
        }
    }

    return converted_guess;
}

bool ask_to_play_again() {
    cout << "\nWould you like to play again? Type Y or N" << endl;
    char input;
    cin >> input;
    return (input == 'Y' || input == 'y');
}

string calculate_time_delta(const chrono::high_resolution_clock::time_point &start_time, const chrono::high_resolution_clock::time_point &end_time)
{
    auto duration = chrono::duration_cast<chrono::seconds>(end_time - start_time);

    long long hours = chrono::duration_cast<chrono::hours>(duration).count();
    duration -= chrono::hours(hours);

    long long minutes = chrono::duration_cast<chrono::minutes>(duration).count();
    duration -= chrono::minutes(minutes);

    long long seconds = duration.count();

    ostringstream calculated_duration;

    calculated_duration << setfill('0') << setw(2) << hours << ":";
    calculated_duration << setfill('0') << setw(2) << minutes << ":";
    calculated_duration << setfill('0') << setw(2) << seconds;

    return calculated_duration.str();

}

void draw_guess(const vector<string>& colors, const vector<string>& converted_guess, int turn_number, int black_pins, int white_pins)
{
    cout << "Turn number: " << turn_number << "    |";

    for(int i = 0; i < converted_guess.size(); i++) {

        cout << " --" << converted_guess[i] << "-- |";

    }
    cout << endl;

    cout << "Black pins: " << black_pins << "   " << endl;
    cout << "White pins: " << white_pins << "   " << endl;
    cout << endl;

    /*
        expected output:

        turn number x   | --red-- | --red-- | --grn-- | --grn-- |  
        Black pins: y
        White pins: z
    */

}

void win_sequence(const vector<string>& computer_colors, int num_guesses, const chrono::high_resolution_clock::time_point& start_time)
{
    auto end_time = chrono::high_resolution_clock::now();
    string time_delta = calculate_time_delta(start_time, end_time);

    cout << "\nYOU WIN! YOU ARE THE" << endl;
    cout << "**** MASTERMIND ****\n" << endl;

    cout << "Number of guesses: " << num_guesses << endl;
    cout << "Total time: " << time_delta << endl;
    cout << "Computer's colors: ";

    for(const string color : computer_colors)
    {
        cout << color << " ";
    }
    cout << endl;

}

void lose_sequence(const vector<string>& computer_colors, const chrono::high_resolution_clock::time_point& start_time)
{
    auto end_time = chrono::high_resolution_clock::now();
    string time_delta = calculate_time_delta(start_time, end_time);

    cout << "YOU LOSE! YOU AREN'T THE" << endl;
    cout << "****** MASTERMIND ******\n" << endl;

    cout << "Total time: " << time_delta << endl;
    cout << "Computer's colors: " << endl; //need to show computer generated colors
    
    for(const string color : computer_colors)
    {
        cout << color << " ";
    }
    cout << endl;
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

vector<string> generate_computer_colors(const vector<string>& colors, int num_pins) {

    random_device random;
    mt19937 generator(random());
    uniform_int_distribution<int> distribution(0, colors.size() - 1);

    vector<string> computer_colors;

    for(int i = 0; i < num_pins; i++) {
        int temp = distribution(generator);
        computer_colors.push_back(colors[temp]);
    }

/*  
    cheat mode to display computer colors

    for(const string single_color : computer_colors)
    {
        cout << single_color << " ";
    }
    cout << endl;
*/

    return computer_colors;
}

int main () {

    vector<string> colors = {"black", "white", "red", "green", "blue", "yellow"};

    intro_sequence();

    bool playing = true;
    while(playing) 
    {
        int num_pins = set_num_pins();
        int num_turns = how_many_turns(num_pins);

        vector<string> computer_colors = generate_computer_colors(colors, num_pins);

        auto start_time = chrono::high_resolution_clock::now();    

        cin.ignore();

        for(int turn_number = 1; turn_number <= num_turns; turn_number++)
        {
            vector<string> guess = get_player_guess(num_pins);

            int black_pins = check_for_black_pins(guess, computer_colors);
            int white_pins = check_for_white_pins(guess, computer_colors);

            if(black_pins == num_pins)
            {
                win_sequence(computer_colors, turn_number, start_time);
                break;
            }
            if(turn_number == num_turns && black_pins != num_pins)
            {
                lose_sequence(computer_colors, start_time);
            }
            vector<string> converted_guess = convert_player_guess(colors, guess, num_pins);

            draw_guess(colors, converted_guess, turn_number, black_pins, white_pins);
        }
        playing = ask_to_play_again(); 
    }
    outro_sequence();

    return 0;        
}