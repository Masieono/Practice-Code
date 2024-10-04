#include <iostream>

/*
    Given two strings s and t, 
    return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed 
    from the original string by deleting some (can be none) of 
    the characters without disturbing the relative positions of 
    the remaining characters. 
    
    (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/

using std::cout;
using std::endl;

std::string get_user_string()
{
    std::string input;
    cout << "Please input string: " << endl;
    std::getline(std::cin, input);

    return input;
}

bool is_subsequence(std::string string_1, std::string string_2)
{
    // two pointer technique, without the squeeze
    int index_1 = 0;
    int index_2 = 0;

    while (index_2 < string_2.size())
    {
        int index_1 = 0;
        int index_2 = 0;

        while (index_2 < string_2.size())
        {
            if (string_1[index_1] == string_2[index_2])
            {
                index_1++;
                index_2++;
            }
            else{
                index_2++;
            }

            if (index_1 == string_1.size())
            {
                return true;
            }
        }

        if(string_1.size() == 0) return true;

    return false;
    }
}

bool ask_to_go_again()
{
    char input;
    cout << "Would you like to do this again? Y or N" << endl;

    while(true)
    {
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        if (input == 'Y' || input == 'y') return true;
        else if (input == 'N' || input == 'n') return false;
        else std::cout << "Invalid input. Please try again: ";
    }
}

int main ()
{
    cout << endl << "Program started." << endl;

    bool running = true;

    while (running)
    {
        std::string input_1 = get_user_string();
        std::string input_2 = get_user_string();

        cout << (is_subsequence(input_1, input_2) ? "Certified subsequence" : "No subsequence found") << endl;

        running = ask_to_go_again();
    }

    cout << "Program ended." << endl;
    return 0;
}