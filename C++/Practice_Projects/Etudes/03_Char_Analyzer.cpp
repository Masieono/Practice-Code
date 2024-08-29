#include <iostream>

/*
    Program does a quick test on ascii number - char conversions
    - will output the ascii number of the given input char
    - will tell you if it is a symbol, number, upper case, or lower case letter
    - if it is an upper case letter, will give the lower case number as well
    - if it is a lower case letter, will give the upper case number as well
*/

using std::cin;
using std::cout;
using std::endl;

void intro_sequence()
{
    cout << "Welcome to word analyzer 9000." << endl;
    cout << "You have chosen well to open this application." << endl;
    cout << endl;
}

char get_user_char()
{
    cout << "Enter character to be analyzed: " << endl;

    char input;
    cin >> input;

    return input;
}

void display_analysis(char input)
{

    int ascii_val = input;

    if (ascii_val > 64 && ascii_val < 91)
        {
            cout << "You have entered the uppercase letter " << input << " with the ascii value of " << ascii_val << endl;
            cout << "The lowercase variant " << char(ascii_val + 32) << " has an ascii value of " << ascii_val + 32 << endl;
        }
    else if (ascii_val > 96 && ascii_val < 123)
        {
            cout << "You have entered the lowercase letter " << input << " with the ascii value of " << ascii_val << endl;
            cout << "The uppercase variant " << char(ascii_val - 32) << " has an ascii value of " << ascii_val - 32 << endl;
        }
    else 
        {
            cout << "You have entered a symbol that looks like '" << input << "'" << endl;
            cout << "The ascii value of that symbol is " << ascii_val << endl;
        }
}

bool new_analysis_prompt()
{
    cout << "Would you like to run analysis on a different input? Y or N\n";

    char input;
    cin >> input;
    return(input == 'Y' || input == 'y');
}

void outtro_sequence()
{
    cout << "Goodbye, and farewell to thee" << endl;
    cout << endl;
}

int main () {

    intro_sequence();

    bool running = true;
    while(running) 
    {
        //get the character from user
        char input = get_user_char();

        //run analysis on the character
        display_analysis(input);

        running = new_analysis_prompt();

        cin.ignore();
    }

    outtro_sequence();

    return 0;
}