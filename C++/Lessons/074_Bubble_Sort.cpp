#include <iostream>
#include <vector>

/*
    Sorting algorithm that checks adjacent elements, switching them if they are out of order.
    0(n^2) time complexity - not good, my dude. 
    The bigger the data set, the slower the sort time. Absolutely do not use on large data.
    By far not the best sorting algorithm and most likely will use another algo.
*/

using std::cout;
using std::endl;

void print_vector(std::vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}

void ascending_bubble_sort(std::vector<int>& input)
{
    for(int i = 0; i < (input.size() - 1); i++)
    {
        for(int j = 0; j < (input.size() - i - 1); j++)
        {
            if (input[j] > input[j + 1])
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

void descending_bubble_sort(std::vector<int>& input)
{
    for(int i = 0; i < (input.size() - 1); i++)
    {
        for(int j = 0; j < (input.size() - i - 1); j++)
        {
            if (input[j] < input[j + 1])
                      // ^ greater than or less than makes the 
                      //   difference between ascending and descending sort 
            {
                int temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

int main () {

    // start with an out of order vector
    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    ascending_bubble_sort(my_vector);
    print_vector(my_vector);

    descending_bubble_sort(my_vector);
    print_vector(my_vector);

    return 0;
}