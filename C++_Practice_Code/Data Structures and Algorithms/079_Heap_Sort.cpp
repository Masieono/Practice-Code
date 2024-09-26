#include <iostream>
#include <vector>

/*



    Time complexity - 

*/

using std::cout;
using std::endl;

void print_vector(std::vector<int>& input)
{
    for(int i : input)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void max_heapify(std::vector<int>& input, int n, int i)
{
    int largest = i;        // initialize largest as root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // if left child is larger than root
    if (left < n && input[left] > input[largest]) largest = left;
    if (right < n && input[right] > input[largest]) largest = right;

    // if largest is not root
    if (largest != i)
    {
        std::swap(input[i], input[largest]);

        max_heapify(input, n, largest);
    }
}

void ascending_heap_sort(std::vector<int>& input)
{
    int n = input.size();

    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(input, n, i);
    }

    // extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        std::swap(input[0], input[i]);

        max_heapify(input, i, 0);
    }
}

void min_heapify(std::vector<int>& input, int n, int i)
{
    int smallest = i;       // initialize smallest as root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // if left child is smaller than root
    if (left < n && input[left] < input[smallest]) smallest = left;
    // if right child is smaller than root
    if (right < n && input[right] < input[smallest]) smallest = right;

    // if smallest is not root
    if (smallest != i)
    {
        std::swap(input[i], input[smallest]);

        // recursively heapify the affected subtree
        min_heapify(input, n, smallest);
    }
}

void descending_heap_sort(std::vector<int>& input)
{
    int n = input.size();

    // build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(input, n, i);
    }

    // extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // move current root to the end
        std::swap(input[0], input[i]);

        // call min heapify on reduced heap
        min_heapify(input, i, 0);
    }
}

int main () {

    std::vector<int> my_vector = {14, 20, 2, 8, 16, 4, 12, 3, 17, 9, 13, 10, 18, 1, 5, 7, 6, 19, 11, 15};
    print_vector(my_vector);

    std::vector<int> new_vector = my_vector;
    ascending_heap_sort(new_vector);
    print_vector(new_vector);

    new_vector = my_vector;
    descending_heap_sort(new_vector);
    print_vector(new_vector);

    return 0;
}