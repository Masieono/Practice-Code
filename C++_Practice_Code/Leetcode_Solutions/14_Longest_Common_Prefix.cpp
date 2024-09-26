#include <iostream>
#include <vector>

/*
    Write a function to find the longest common 
    prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".
    
    Example 1:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"

    Example 2:

    Input: strs = ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
*/

int get_vector_size()
{
    int response;
    std::cout << "How many words will we analyze: ";
    std::cin >> response;

    return response;
}

std::vector<std::string> input_vector_contents(int size)
{
    std::vector<std::string> populated_vector(size);
    for (int i = 0; i < size; i++)
    {
        std::string response;
        std::cout << "Enter word #" << i + 1 << ": ";
        std::cin >> response;
        std::cin.ignore(1000, '\n');

        populated_vector[i] = response;
    }

    return populated_vector;
}

std::string longest_common_prefix(std::vector<std::string>& input)
{
    if (input.empty()) return "";
    if (input[0].empty()) return "";

    //build a new string
    std::string result;

    //character position scan
    for (int i = 0; i < input[0].size(); i++)
    {
        // word scan
        for(int j = 1; j < input.size(); j++)
        {
            // compare i letter of first word
            // against all other i letter
            // break as soon as there is a mismatch
            if (i >= input[j].size() || input[0].at(i) != input[j].at(i))
            {
                std::cout << "Character mismatch" << std::endl;
                return result;
            }

        }
        // getting here assumes there was a full scan of common i letters.

        result += input[0][i];
    }

    return result;
}

bool ask_to_go_again()
{
    char input;
    std::cout << "Would you like to do this again? Y/N" << std::endl;

    while(true)
    {
        std::cin >> input;
        // std::cin.ignore(1000, '\n');

        if (input == 'Y' || input == 'y') return true;
        else if (input == 'N' || input == 'n') return false;
        else std::cout << "Invalid input. Please try again: ";
    }
}

int main()
{
    std::cout << "Beep Boop. Program starting." << std::endl;

    bool running = true;

    while (running)
    {

        int vector_size = get_vector_size();
        std::vector<std::string> input = input_vector_contents(vector_size);

        std::string result = longest_common_prefix(input);

        std::cout << "Longest common prefix is: "<< result << std::endl;

        running = ask_to_go_again();
    }

    std::cout << "Program ending." << std::endl;
    return 0;
}