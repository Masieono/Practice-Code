#include <iostream>
#include <queue>

/*
    First in, first out (FIFO) data structure
    
    Much like a line of people at the store.
    first in line gets served or seen first.

    Designed for holding elements prior to processing
    Linear data structure

    Similar functions include:
        push() adds element to the back of the queue
        pop() removes the front element of the queue
        front() returns a copy of the value of head element
        back() returns a copy of the value of tail element
        empty() returns boolean, true if queue is empty
        size() returns number of elements in queue
        swap() will replace the queue with contents of another queue

    Beginning of queue (first element) is called the head
    End (last element) is called the tail

    Enqueue adds to the tail, 
    Dequeue removes from the head.

    Particularly useful for keyboard input buffers,
    Printer jobs (completed in order they were sent to the printer)
    Also used in linked lists, priority queues, and breadth-first search

*/

using namespace std;

void walmart_checkout(queue<string>& customers)
{
    while(!customers.empty())
    {
        cout << customers.front() << " has checked out and left the store" << endl;
        customers.pop();
    }

    cout << endl;
}

int main () {

    cout << "Welcome to walmert" << endl;
    cout << endl;

    queue<string> checkout_line;

    string customer1 = "Mary Jane";
    cout << customer1 << " has entered walmert" << endl;
    checkout_line.push(customer1);

    string customer2 = "Tom Brady";
    cout << customer2 << " has entered walmert" << endl;
    checkout_line.push(customer2);

    string customer3 = "Hewlett Packard";
    cout << customer3 << " has entered walmert" << endl;
    checkout_line.push(customer3);

    walmart_checkout(checkout_line);

    cout << "thank u come again" << endl;

    return 0;
}