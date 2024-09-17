#include <iostream>
#include <vector>

/*
    Given an array of integers sorted by increasing size,
    return an array of their squares also sorted by increasing size


    Example: [-4, -1, 2, 3, 4]
    Output: [1, 4, 9, 16, 16]

    Negative integers end up appropriately sorted

    Shooting for an O(n) solution - only one pass through the vector.
    REMEMBER - this is under the 'two pointer' section of algomap!
*/

using std::cout;
using std::endl;

void intro()
{
    cout << "Welcome to Array Squarer 9000" << endl << endl;
}

int get_array_size()
{
    int size;
    cout << "How big a vector we talking here? ";
    std::cin >> size;

    return size;
}

std::vector<int> get_array_contents(int size)
{
    std::vector<int> array(size);

    for(int i = 0; i < size; i++)
    {
        int temp;
        cout << "Please enter number " << (i + 1) << " out of " << size << ": ";
        std::cin >> temp;
        array[i] = temp;
    }

    return array;
}

std::vector<int> squared_array(std::vector<int>& input)
{
    int n = input.size();
    std::vector<int> solution(n);
    

    // two pointers
    int first = 0;
    int last = n - 1;

    // index for storing values into solution array
    int index = n - 1;

    while(first <= last)
    {
        // compare the squares of first and last digits,
        int left_square = input[first] * input[first];
        int right_square = input[last] * input[last];

        if(left_square > right_square)
        {
            solution[index] = left_square;
            first++;
        }
        else
        {
            solution[index] = left_square;
            last--;
        }
        index--;
    }

    return solution;
}

void print_array(std::vector<int> input)
{
    for(int number : input)
    {
        cout << number << " ";
    }
    cout << endl;
}

bool run_program_again()
{
    char response;
    cout << "Would you like to try again? Y/N ";
    std::cin >> response;

    return (response == 'Y' || response == 'y');
}

int main()
{
    intro();

    bool running = true;
    while(running)
    {
        int array_size = get_array_size();
        std::vector<int> array = get_array_contents(array_size);

        std::vector<int> solution = squared_array(array);        

        print_array(array);
        print_array(solution);

        running = run_program_again();
    }

    cout << "Goodbye." << endl << endl;

    return 0;
}