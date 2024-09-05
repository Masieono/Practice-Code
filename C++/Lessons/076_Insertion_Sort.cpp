#include <iostream>
#include <vector>

/*
    Takes the second variable in an index and puts it in a temp spot. Then checks to the left 
    of it for any lower/higher value. If there is a lower/higher value, it moves the value to 
    the right. Once there are no more lower/higher values, it places the temp value before the
    moved variables.

    Less steps than bubble sort and selection sort, but still a 'bad' sorting algo.
    0(n^2) and bad for big data

*/

using std::cout;
using std::endl;

void print_vector(std::vector<int>& input)
{
    for(int i : input)
    {
        cout << i << " ";
    }
    cout << endl;
}

void ascending_insertion_sort(std::vector<int>& input)
{
    for(int i = 1; i < input.size(); i++)
    {
        int temp = input[i];
        int j = i - 1;

        while(j >= 0 && input[j] > temp)
        {
            input[j + 1] = input[j];
            j--;
        }
        input[j +  1] = temp;
    }
}

int main () {

    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    ascending_insertion_sort(my_vector);
    print_vector(my_vector);

    return 0;
}