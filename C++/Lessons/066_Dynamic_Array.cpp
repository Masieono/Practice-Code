#include <iostream>
#include <vector>

/*
    Simply an array that is resizable, 
    more flexible than a static array

    Dynamic array starts as a static array
    with a fixed size, but instantiates a 
    new array once the capacity necessitates it.

    Advantages - random access of elements,
    thanks to the iterated list.
    Good locality of reference and data cache utilization.
    Easy to insert/delete data at the end.

    Disadvantages - uses more memory than a linked list.
    Shifting elements can be time consuming,
    Expanding/shrinking the array can be time consuming

    Very similar in methods: empty(), size(), max_size(),
    clear(), insert(), erase(), push_back(), pop_back(), 
    resize(), and swap()    

    Java = ArrayList
    C++ = Vector
    Javascript = Array
    Python = List
*/

using namespace std;

void print_vector(const vector<string> &vector)
{
    for (string element : vector)
    {
        cout << element << " ";
    }
    cout << endl << endl;
}


int main () {

    vector<string> my_vector = {"orange", "red", "yellow", "green"};

    my_vector.push_back("purple");

    cout << "Number of colors: " << my_vector.size() << endl;

    print_vector(my_vector);

    cout << "Current possible number of colors: " << my_vector.capacity() << endl;
    cout << "Max possible number of colors: " << my_vector.max_size() << endl;

    cout << my_vector[2] << endl;

    //insert_element(my_vector, "Periwinkle", 3);

    return 0;
}