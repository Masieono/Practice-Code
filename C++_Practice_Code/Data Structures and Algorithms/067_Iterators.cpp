#include <iostream>
#include <vector>
#include <list>
#include <queue>

/*
    Common container types (such as arrays, lists, and queues)
    have iterator functions to help index through their contents.
    This is known as "range access."

    begin()
    end()
*/

using namespace std;

int main () {

    list<int> my_list = {1, 2, 3, 4, 5};
    list<int>::iterator l_it = my_list.begin();
    //establish an iterator


    // peep the blank first section of the for loop
    // normally we would declare int i = 0;
    // but we've already configured an iterator above
    for (; l_it != my_list.end(); l_it++)
    {
        *l_it *= 2;
        cout << *l_it << " " << endl;
    }
    
    // To use the iterator, it must be dereferenced with *
    // The iterator points to the values within the container

    // Iterators are more than just integer index numbers, they
    // have the ability to point to various elements within container

    vector<int> my_vector = {6, 7, 8, 9, 10};
    vector<int>::iterator v_it = my_vector.begin();

    for (; v_it != my_vector.end(); v_it++)
    {
        *v_it = (*v_it % 2) + 5;
        cout << *v_it << " " << endl;
    }
    // pretty much the same, but using vectors

    // queues do not offer iterator/range access,
    // as it goes against their intended nature.

    // lists, maps, sets, arrays, 
    // and vectors offer range access.

    return 0;
}