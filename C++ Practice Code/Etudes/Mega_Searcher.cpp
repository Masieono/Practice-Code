#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

/*
    Similar to the mega sorter, this program benchmarks various search algorithms.

    Program asks for 

    Linear Search
    Binary Search
    Interpolation Search
*/

using std::cout;
using std::endl;

void intro_sequence()
{
    cout << "WELCOME TO MEGA SEARCH 9000" << endl << endl; 
}


int get_size()
{
    int size;
    cout << "How big would you like the array to be? ";
    std::cin >> size;

    // add error handling for non-numerical and negative values

    return size;
}

std::vector<int> create_vector(const int size)
{
    std::vector<int> ordered_vector(size);

    for(int i = 0; i < size; i++)
    {
        ordered_vector[i] = i + 1;
    }

    return ordered_vector;
}

std::vector<int> shuffle_vector(const std::vector<int> ordered_vector)
{
    std::vector<int> shuffled_vector = ordered_vector;


    // shuffle the vector's contents


    return shuffled_vector;
}

int get_search_num(int vector_size)
{
    int search_num;
    cout << "Please enter a number to search for: ";
    std::cin >> search_num;

    // still needs error handling for non numerical, negative, and out of range values

    return search_num;
}


bool ask_to_go_again()
{
    char response;
    cout << "Would you like to run this program again? Y/N ";
    std::cin >> response;

    // add error handling and cin.ignore()

    return (response == 'Y' || response == 'y');
}

int main()
{
    intro_sequence();

    bool running = true;
    while(running)
    {
        // prompt user for the size of a vector 
        int vector_size = get_size();
        // generate an ordered and shuffled vector of that size
        std::vector<int> ordered_vector = create_vector(vector_size);
        std::vector<int> randomized_vector = shuffle_vector(ordered_vector);


        // prompt user for a number to search for within the vector
        int search_num = get_search_num(vector_size);

        // run linear search on ordered vector

        // run binary search on ordered vector (won't work on shuffled vector probably?)

        // run interpolation search


        running = ask_to_go_again();
    }



    return 0;
}