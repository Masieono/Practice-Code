#include <iostream>
#include <vector>
#include <sstream>

#include "header_example.h"

/*
    This is the actual implementation file, where the 'guts'
    of each function must be defined. 

    There is no int main()
*/

int get_num_one() {
    std::cout << "Please enter first number for operations: " << std::endl;
    int num_1;
    std::cin >> num_1;
    return num_1;
}

int get_num_two() {
    std::cout << "Please enter second number for operations: " << std::endl;
    int num_2;
    std::cin >> num_2;
    return num_2;
}

int add_2_nums(int x, int y) {
    return x + y;
}

void print_sum(int sum) {
    std::cout << "The sum of the numbers you have entered is " << sum << std::endl;
}

std::vector<std::string> get_text() {
    std::cout << "Please enter some text to print to the terminal: " << std::endl;

    std::cin.ignore();

    std::vector<std::string> input_message;
    std::string raw_input;
    std::getline(std::cin, raw_input);
    std::istringstream iss(raw_input);
    std::string single_word;
    while (iss >> single_word)
    {
        input_message.push_back(single_word);
    }
    return input_message;
}

void print_message(const std::vector<std::string>& message) {
    std::cout << "You have entered the text '";

    for (int i = 0; i < message.size(); i++)
    {
        if (i < message.size() - 1)
        {
            std::cout << message[i] << " ";
        }
        else 
        {
            std::cout << message[i];
        }

    }

    std::cout << "'" << std::endl;
    std::cout << "What lovely prose you have!" << std::endl;
}

bool prompt_to_go_again() {
    std::cout << "Would you like to run this program again? y/n" << std::endl;
    char input;
    std::cin >> input;
    return (input == 'Y' || input == 'y');

    std::cin.ignore();
}

void outtro_sequence() {
    std::cout << "Thank you for running this program." << std::endl;
    std::cout << "It has been an honor calculating for you" << std::endl;
    std::cout << "Beep boop, shutting down now." << std::endl << std::endl;
}