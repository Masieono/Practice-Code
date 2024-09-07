#include <iostream>
#include <vector>

/*
    Another recursive sorting algo. Takes a variable at the end of the array as a pivot.
    Sorts the pivot into location between values higher and lower than it, and splits the 
    higher/lower sections, remembering the indices of each section. Repeats the process of 
    finding a new pivot on each sub-array until the array is 1 unit long. 

    Best case scenario runs at O(n log n) 
    but worst case scenario is O(n^2) if array is already or close to being sorted
*/

void print_vector(std::vector<int>& input)
{
    for(int i : input)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& input, int start, int end)
{
    int pivot = input[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++)
    {
        if(input[j] < pivot)
        {
            i++;
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
        }
    }
    i++;

    int temp = input[i];
    input[i] = input[end];
    input[end] = temp;

    return i;    
}

void ascending_quick_sort(std::vector<int>& input, int start, int end)
{
    if(end <= start) return;    // base case

    int pivot = partition(input, start, end);
    ascending_quick_sort(input, start, pivot - 1);
    ascending_quick_sort(input, pivot + 1, end);
}

int main () {

    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    ascending_quick_sort(my_vector, 0, my_vector.size());
    print_vector(my_vector);

    return 0;
}