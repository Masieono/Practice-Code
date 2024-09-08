#include <iostream>
#include <vector>

/*
    Recursive function that divides the array in half until the base unit of the array is 1.
    The units are sorted, then merged back together in order.

    O(n log n) complexity - better than quadratic time algos like bubble, selection, and insertion sort
    Rivals quicksort and heapsort

    Uses more memory space than other sorts as it has to store data in new sub arrays.
*/

void print_vector(std::vector<int>& input)
{
    for(int i : input)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void merge(std::vector<int>& left_array, std::vector<int>& right_array, std::vector<int>& array)
{
    int left_size = array.size()/2;
    int right_size = array.size() - left_size;
    int i = 0, l = 0, r = 0; // indices

    while(l < left_size && r < right_size)
    {
        if(left_array[l] < right_array[r])
        {
            array[i] = left_array[l];
            i++;
            l++;
        }
        else 
        {
            array[i] = right_array[r];
            i++;
            r++;
        }
    }
    while(l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }
    while(r < right_size)
    {
       array[i] = right_array[r];
       i++;
       r++; 
    }
}

void ascending_merge_sort(std::vector<int>& input)
{
    int length = input.size();
    if (length <= 1) return; //base case

    int middle = length/2;
    std::vector<int> left_array(middle);
    std::vector<int> right_array(length - middle);

    int i = 0; // left array
    int j = 0; // right array

    for(; i < length; i++)
    {
        if(i < middle)
        {
            left_array[i] = input[i];
        }
        else 
        {
            right_array[j] = input[i];
            j++;
        }
    }
    ascending_merge_sort(left_array);
    ascending_merge_sort(right_array);
    merge(left_array, right_array, input);
}

int main () {

    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    ascending_merge_sort(my_vector);
    print_vector(my_vector);


    return 0;
}