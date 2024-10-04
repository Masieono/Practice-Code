#include <iostream>
#include <vector>
// #include <algorithm>

/*
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k 
that has the maximum average value and return this value. 

Any answer with a calculation error less than 10^-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:

Input: nums = [5], k = 1
Output: 5.00000
*/

int get_vector_size()
{
    std::cout << "How big is the vector: ";
    int size;
    std::cin >> size;

    return size;
}

std::vector<int> get_vector_contents(int size)
{
    std::vector<int> populated_vector(size);
    for (int i = 0; i < size; i++)
    {
        int response;
        std::cout << "Enter number " << i+1 << ": ";
        std::cin >> response;

        populated_vector[i] = response;
    }

    std::cout << std::endl;
    std::cout << "Here is the inputted vector: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << populated_vector[i] << " ";
    }
    std::cout << std::endl;

    return populated_vector;
}

int get_k_value()
{
    int k_value;
    std::cout << "What is the K value? ";
    std::cin >> k_value;

    return k_value;
}

double find_max_average_2(std::vector<int>& nums, int k)
{
    // add up the left-most window
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }
    double solution = sum;

    // slide the window
    for (int i = k; i < nums.size(); i++)
    {
        // remove the first value, 
        sum = sum + nums[i] - nums[i - k];

        // update the maximum amount
        solution = std::max(solution, sum);
    }    

    return solution / k;
}

double find_max_average(std::vector<int>& nums, int k)
{
    // Keep in mind this is a sliding window solution!
    int left = 0;
    int right = k - 1;

    // find the left-most window average
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    double solution = static_cast<double>(sum) / k;

    while (right < nums.size() - 1)
    {
        // move the window

        sum -= nums[left];
        left++;
        right++;
        sum += nums[right];

        // compute a new average
        double average = static_cast<double>(sum) / k;

        // save the number to solution if it is higher than current solution
        if(average > solution)
        {
            solution = average;
        }
    }

    return solution;
}

void print_answer(double max_average)
{
    std::cout << "The maximum average is: " << max_average << std::endl;
}

bool ask_to_go_again()
{
    char input;
    std::cout << "Would you like to do this again? Y or N" << std::endl;

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
    std::cout << "Program starting..." << std::endl;

    bool running = true;
    while(running)
    {
        int size = get_vector_size();
        std::vector<int> vector = get_vector_contents(size);
        int k_value = get_k_value();

        // first solution I thought up
        print_answer(find_max_average(vector, k_value));

        // more eloquent solution
        print_answer(find_max_average_2(vector, k_value));

        running = ask_to_go_again();
    }
    
    std::cout << "Shutting down..." << std::endl;

    return 0;
}