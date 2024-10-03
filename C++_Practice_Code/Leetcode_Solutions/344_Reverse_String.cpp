#include <iostream>
#include <vector>
#include <algorithm>

/*
Write a function that reverses a string. 
The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/


std::vector<char> get_input_word()
{
    std::cout << "Enter string to be reversed: ";
    std::string word;
    std::getline(std::cin, word);

    return std::vector<char>(word.begin(), word.end());
}

void print_word_vector(std::vector<char>& word)
{
    for (char letter : word)
    {
        std::cout << letter;
    }
    std::cout << std::endl;
}

void reverse_string(std::vector<char>& s)
{
    // can only take up O(1) extra memory
    // suggests that theres only one temp char variable
    // two pointer solution
    int beginning = 0;
    int ending = s.size()-1;
    char temp;

    while (beginning < ending)
    {
        temp = s[beginning];
        s[beginning] = s[ending];
        s[ending] = temp;
        beginning++;
        ending--;
    }
}

bool ask_to_go_again()
{
    char input;
    std::cout << "Would you like to do this again? Y/N" << std::endl;

    while(true)
    {
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        if (input == 'Y' || input == 'y') return true;
        else if (input == 'N' || input == 'n') return false;
        else std::cout << "Invalid input. Please try again: ";
    }
}

int main()
{
    std::cout << "Program starting." << std::endl;

    bool running = true;
    while(running)
    {

        std::vector<char> input_word = get_input_word();
        print_word_vector(input_word);

        reverse_string(input_word);

        std::cout << "Reversing string..." << std::endl;

        print_word_vector(input_word);



        running = ask_to_go_again();
    }

    std::cout << "Shutting down. Beep boop";
    return 0;
}

