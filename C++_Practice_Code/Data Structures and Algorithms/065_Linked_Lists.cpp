#include <iostream>
#include <list>

/*
    Arrays store elements in contiguous memory addresses.
    Because of this, it is not efficient or simple to insert
    an element somewhere within the array. You would have to
    shift elements over until you have an appropriate space
    to store an element. The same goes for deleting an element
    within an array.

    Linked lists are better for adding and deleting elements within
    their structures, due to the way they are set up:

    Each element within the linked list has 1) its own data, and 
    2) the memory address of the next member on the list. This also
    means a linked list is not stored in memory contiguously.

    To insert an element within the list, the memory address of the
    n-1 element must be updated to the new list entry, and the new list
    entry's memory address points to the nth member of the list.

    To delete an element within a linked list at n position, simply update 
    n-1 pointer to n+1's address. 

    Linked lists are better for dynamic manipulation, but aren't as good
    when searching for specific elements. 

    Single linked list - can iterate from top to bottom.

    data        data        data        data
    pointer ->  pointer ->  pointer ->

    Double linked list - can iterate both ways, but is more memory expensive

             <- pointer  <- pointer  <- pointer
    data        data        data        data
    pointer ->  pointer ->  pointer ->

    Operaters include:
        front() returns the first element
        back() returns the last element
        empty() returns true if container is empty
        size() returns the number of elements
        max_size() returns maximum possible number of elements

        clear() clears the contents
        insert() inserts elements
        push_back() adds element to the end
        push_front() adds element to the beginning
        pop_back() removes the last element
        pop_front() removes the first element
        resize() changes number of elements

        remove() and remove_if() for removing elements
        reverse() the order of elements
        unique() removes consecutive duplicate elements
        sort() the elements

        Uses are similar to stacks and queues,
        GPS navigation, or music playlists.
*/

using namespace std;

void print_list(const list<char> &list)
{
    for (char letter : list)
    {
        cout << letter;
    }
    
    cout << endl << endl;
}

int main () {

    list<char> linked_string_list;

    linked_string_list.push_back('H');
    linked_string_list.push_back('e');
    linked_string_list.push_back('l');
    linked_string_list.push_back('l');
    linked_string_list.push_back('o');
    linked_string_list.push_back(' ');
    linked_string_list.push_back('W');
    linked_string_list.push_back('o');
    linked_string_list.push_back('r');
    linked_string_list.push_back('l');
    linked_string_list.push_back('d');
    linked_string_list.push_back('!');
    
    cout << "Full list message: \n" << endl;
    print_list(linked_string_list);

    linked_string_list.pop_back();
    linked_string_list.push_back('?');
    cout << "Altered list message: \n" << endl;
    print_list(linked_string_list);

    linked_string_list.sort();
    cout << "Sorted list message: \n" << endl;
    print_list(linked_string_list);

    linked_string_list.unique();
    cout << "Adjacent duplicates removed: \n" << endl;
    print_list(linked_string_list);

    linked_string_list.reverse();
    cout << "Reverse reverse!\n" << endl;
    print_list(linked_string_list);

    cout << "The message could have been \n" << linked_string_list.max_size() << " characters long." << endl;    cout << "But it is only " << linked_string_list.size() << " characters long." << endl;

    return 0;
}