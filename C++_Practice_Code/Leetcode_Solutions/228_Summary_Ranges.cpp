#include <iostream>
#include <vector>

/*
    You are given a sorted unique integer array nums.

    A range [a,b] is the set of all integers from a to b (inclusive).

    Return the smallest sorted list of ranges that cover all 
    the numbers in the array exactly. That is, each element of 
    nums is covered by exactly one of the ranges, and there is 
    no integer x such that x is in one of the ranges but not in nums.

    Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b
 
    Example 1:

    Input: nums = [0,1,2,4,5,7]
    Output: ["0->2","4->5","7"]
    Explanation: The ranges are:
    [0,2] --> "0->2"
    [4,5] --> "4->5"
    [7,7] --> "7"

    Example 2:

    Input: nums = [0,2,3,4,6,8,9]
    Output: ["0","2->4","6","8->9"]
    Explanation: The ranges are:
    [0,0] --> "0"
    [2,4] --> "2->4"
    [6,6] --> "6"
    [8,9] --> "8->9"
*/

int get_array_size()
{
    int response;
    std::cout << "How big is the array?";
    std::cin >> response;
    std::cin.ignore(1000, '\n');

    // std::cout << std::endl;
    return response;
}

std::vector<int> populate_array(int size)
{
    std::vector<int> array(size);

    for (int i = 0; i < size; i++)
    {
        int entry;
        std::cout << i + 1 << ") Enter number: ";
        std::cin >> entry;
        // std::cin.ignore(1000, '\n');

        array[i] = entry;

        // std::cout << std::endl;
    }

    std::cout << "Here is the array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return array;
}

std::vector<std::string> summary_ranges(std::vector<int> input)
{
    std::vector<std::string> solution;
    if (input.empty()) return solution;

    int beginning = input[0];
    int ending;

    for (int i = 1; i < input.size(); i++)
    {
        // if the previous number is more than one off from the current number, 
        // we're at a beginning of a new sequence
        if (input[i-1] < (input[i] - 1))
        {
            // denote the ending
            ending = input[i - 1];

            // if the beginning and the end are the same number,
            // just push back the beginning value
            if (beginning == ending) 
            {
                solution.push_back(std::to_string(beginning));
            }
            else
            {
                solution.push_back(std::to_string(beginning) + "->" + std::to_string(ending));
            }

            beginning = input[i];
        }
    }

    ending = input.back();
    if (beginning == ending)
    {
        solution.push_back(std::to_string(beginning));
    }
    else
    {
        solution.push_back(std::to_string(beginning) + "->" + std::to_string(ending));
    }

    std::cout << "Here is the summary array: ";
    for (std::string entry : solution)
    {
        std::cout << entry << ", ";
    }
    std::cout << std::endl;

    return solution;
}

void print_array(const std::vector<std::string>& input)
{
    for (std::string string : input)
    {
        std::cout << string << " ";
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
    while (running)
    {
        int size = get_array_size();

        std::vector<int> populated_array = populate_array(size);

        std::vector<std::string> solution = summary_ranges(populated_array);
        print_array(solution);

        running = ask_to_go_again();
    }

    std::cout << "Program ending." << std::endl;
    return 0;
}