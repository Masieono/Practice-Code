#include <iostream>
#include <vector>

/*
    Scan through array, keeping track of the minimum value. At the end of each iteration, it
    swaps values to put the minimum value at the beginning.
    Another 0(n^2) time complexity. Poor choice with big data.
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

void ascending_selection_sort(std::vector<int>& input)
{
    for(int i = 0; i < input.size() - 1; i++)
    {
        int min = i;

        for(int j = (i + 1); j < input.size(); j++)
        {
            if(input[min] > input[j])
            {
                min = j;
            }
        }
        int temp = input[i];
        input[i] = input[min];
        input[min] = temp; 
    }
}

void descending_selection_sort(std::vector<int>& input)
{
    for(int i = 0; i < input.size() - 1; i++)
    {
        int max = i;

        for(int j = (i + 1); j < input.size() ; j++)
        {
            if(input[max] < input[j])
            {
                max = j;
            }
        }
        int temp = input[i];
        input[i] = input[max];
        input[max] = temp; 
    }
}

int main () {

    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    ascending_selection_sort(my_vector);
    print_vector(my_vector);

    descending_selection_sort(my_vector);
    print_vector(my_vector);

    return 0;
}