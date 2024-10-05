#include <iostream>
#include <vector>

/*
    238. Product of Array Except Self

    Given an integer array nums, return an array 
    answer such that answer[i] is equal to the product 
    of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is 
    guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) 
    time and without using the division operation.
    
    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]

    Example 2:

    Input: nums = [-1,1,0,-3,3]
    Output: [0,0,9,0,0]
    
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
    std::vector<int> vector(size);

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter number " << i + 1 << ": ";

        int temp;
        std::cin >> temp;

        vector[i] = temp;
    }
    return vector;
}

std::vector<int> product_except_self(std::vector<int>& nums)
{
    std::vector<int> answer(nums.size());

    int prefix_product = 1;
    // calculate the suffix product
    for(int i = 0; i < nums.size(); i++)
    {
        answer[i] = prefix_product;
        prefix_product *= nums[i];
    }

    int suffix_product = 1;
    // calculate the prefix product
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        answer[i] *= suffix_product;
        suffix_product *= nums[i];
    }

    return answer;
}

void print_vector(std::string name, std::vector<int> input)
{
    std::cout << name << " contents: ";

    for(int i = 0; i < input.size(); i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
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
    std::cout << "Program starting..." << std::endl;

    bool running = true;
    while(running)
    {
        std::vector<int> test_case_1{1, 2, 3, 4};
        std::vector<int> test_case_2{-1, 1, 0, -3, 3};

        std::vector<int> test_result_1 = product_except_self(test_case_1);
        std::vector<int> test_result_2 = product_except_self(test_case_2);

        print_vector("test case 1", test_case_1);
        print_vector("test result 1", test_result_1);
        print_vector("test case 1", test_case_2);
        print_vector("test result 1", test_result_2);

        int size = get_vector_size();
        std::vector<int> custom_test = get_vector_contents(size);
        std::vector<int> custom_result = product_except_self(custom_test);

        print_vector("custom case", custom_test);
        print_vector("custom result", custom_result);

        running = ask_to_go_again();
    }

    std::cout << "Shutting down. Beep boop." << std::endl;

    return 0;
}