#include <iostream>
#include <vector>
#include <sstream>

/*
    Program accepts a user inputted string
    and does simple analysis of the string.

    The program will tell you how many
    different words have been inputted, and
    whether or not any of those words are a
    "magic" word (words that start with 'm')
*/

using namespace std;

void intro_sequence()
{
    cout << "Welcome to word analyzer 9000." << endl;
    cout << "You have chosen well to open this application." << endl;
    cout << endl << endl;
}

vector<string> get_user_string()
{
    vector<string> user_input;

    cout << "Enter text to be analyzed: " << endl;
    string raw_input;
    getline(cin, raw_input);

    istringstream iss(raw_input);
    string single_word;

    while (iss >> single_word)
    {
        user_input.push_back(single_word);
    }

    return user_input;
}

int string_word_count(const vector<string>& input)
{
    return input.size();
}

vector<string> find_magic_words(const vector<string>& input)
{
    // words that start with 'M' or 'm' are magic words
    vector<string> magic_words;

    for(const string& word : input)
    {
        if(!word.empty() && word[0] == 'M' || word[0] == 'm')
        {
            magic_words.push_back(word);
        }
    }

    return magic_words;
}

void display_final_analysis(int num_words, const vector<string>& magic_words)
{
    cout << "Analysis complete.\n\n";
    cout << "Number of words inputted: " << num_words << "\n\n";
    cout << "Number of magic words found: " << magic_words.size() << "\n\n";

    for(int i = 0; i < magic_words.size(); i++)
    {
        cout << (i + 1) << ") " << magic_words[i] << "\n";
    }
    
    cout << "Thank you for your time.\n";
}

bool new_analysis_prompt()
{
    cout << "Would you like to run analysis on a different input Y or N\n";

    char input;
    cin >> input;
    return(input == 'Y' || input == 'y');
}

int main () {

    intro_sequence();

    bool running = true;
    while(running) 
    {
        // Capture an input string and convert it to vector of individual words
        vector<string> input = get_user_string(); 

        // Various analysis on the vector of words
        int num_words = string_word_count(input);
        vector<string> magic_words = find_magic_words(input);

        // every above function will need to be passed to the below function
        display_final_analysis(num_words, magic_words);

        // Ask to run program again on a new input
        running = new_analysis_prompt();

        cin.ignore();
    }

    return 0;
}