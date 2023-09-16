#include <iostream>

/*
    Big O notation - The rate of how code slows as data grows.

    When a function parses or operates on a data structure, 
    the time it takes to complete the function will inevitably 
    be longer if the data structure is larger.

    Big O describes the performance of an algorithm as the amount
    of data increases. It focuses on the operations within an
    algorithm, ignoring any machine-side efficiencies.

    Examples: 
    
        O(1) "Oh of one"
        O(n) "Oh of n"
        O(log n) "oh of log n"
        O(n^2) "oh of n squared"

        n = number of data entries (integer value)

    Smaller operations to the general equation such as O(n+1) are 
    generally reduced down, as the difference becomes negligible 
    in larger data sets.
*/

using std::cout;

/*
    O(n) linear time complexity

    The size of n directly correlates with the time it takes
    for the algorithm to complete.

    Examples of this include
        Looping through elements in an array
        Searching through a linked list
*/

int linear_add_int(int n) {
    int sum = 0;
   
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
   
    return sum;
}

/*
    0(1) constant time complexity. 

    Regardless of the size of n, there is a constant execution
    time. This is much better than linear time in terms of 
    execution speed.

    Examples of this include:
        Random access of an element within an array
        Inserting at the beginning of a linked list
*/

int constant_add_int(int n) {

    int sum = n * (n + 1) / 2;
    return sum;

}

/*
    O(log n) time complexity

    As n increases, the additional execution time decreases.
    This is similar to constant time complexity, although time
    does still increase as n increases

    Examples of this include:
        Binary search
*/

/*
    O(n log n) Quasilinear time complexity

    Examples of this include
        Quick sort
        Merge sort
        Heap sort
*/

/*
    O(n^2) Quadratic time complexity

    As n increases, it will take progressively longer to execute.

    Examples of this include
        Insertion sort
        Selection sort
        Bubble sort 
*/

/*
    O(n!) Factorial time complexity

    Examples of this include 
        Traveling salesman problem
*/

int main () {

    return 0;
}