#include <iostream>
#include <unordered_map>

/*
    given a roman numeral represented as a string, return the integer

    test cases: III = 3
                LVIII = 58
                MCMXCIV = 1994
*/

std::string get_input_string()
{
    std::cout << "Enter a roman numeral: ";
    std::string input;
    std::getline(std::cin, input);

    return input;
}

int roman_to_integer(std::string s)
{
    int solution = 0;
    int previous_value = 0;

    // build a map with roman numeral values
    std::unordered_map<char, int> map; 
    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (i+1 < s.size() && map[s[i]] < map[s[i+1]])
        {
            solution -= map[s[i]];
        }
        else
        {
            solution += map[s[i]];
        }
    }

    return solution;
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

    while (running)
    {
        std::string input_string = get_input_string();
        std::cout << input_string << std::endl; 

        int solution = roman_to_integer(input_string);
        std::cout << solution << std::endl;

        running = ask_to_go_again();
    }

    std::cout << "Program ending." << std::endl;
    return 0;
}