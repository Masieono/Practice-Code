#include <iostream>
#include <vector>


/*
    Given a 1-indexed array of integers numbers that is 
    already sorted in non-decreasing order, find two numbers 
    such that they add up to a specific target number. Let 
    these two numbers be numbers[index1] and numbers[index2] 
    where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, 
    added by one as an integer array [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. 
    You may not use the same element twice.

    Your solution must use only constant extra space. 

    Example 1:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

    Example 2:

    Input: numbers = [2,3,4], target = 6
    Output: [1,3]
    Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

    Example 3:

    Input: numbers = [-1,0], target = -1
    Output: [1,2]
    Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/


std::vector<int> two_sum_II(std::vector<int> numbers, int target)
{
    std::vector<int> solution(2, 0);

    int beginning = 0;
    int ending = numbers.size() - 1;

    while (beginning < ending)
    {
        if (numbers[beginning] + numbers[ending] < target)
        {
            beginning++;
        }
        else if (numbers[beginning] + numbers[ending] == target)
        {
            solution[0] = beginning + 1;
            solution[1] = ending + 1;

            return solution;
        }
        else
        {
            ending--;
        }
    }

    return solution;
}

void print_vector(std::string name, std::vector<int> vector)
{
    std::cout << name << ": ";
    for(int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Program starting..." << std::endl;

    std::vector<int> test_case_1{2, 7, 11, 15};
    std::vector<int> result_1 = two_sum_II(test_case_1, 9);
    print_vector("test case 1", test_case_1);
    print_vector("result 1", result_1);

    std::vector<int> test_case_2{2, 3, 4};
    std::vector<int> result_2 = two_sum_II(test_case_2, 6);
    print_vector("test case 2", test_case_2);
    print_vector("result 2", result_2);

    std::vector<int> test_case_3{-1, 0};
    std::vector<int> result_3 = two_sum_II(test_case_3, -1);
    print_vector("test case 3", test_case_3);
    print_vector("result 3", result_3);

    std::cout << "Shutting down. Beep boop." << std::endl;

    return 0;
}