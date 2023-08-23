#include <iostream>
#include <queue>

/*
    Priority queues are similar to normal queues,
    but elements have a marginal level of sorting
    based on priority criteria before they are served 

    Higher priority elements are served before 
    lower priority elements. Depends on the data type
    within the queue - 
    
    a queue of integers will serve high to low numbers
    a queue of strings will serve in alphabetical order

    There is an option to customize a comparator in order
    for your priority queue to order itself based on user-
    defined ordering logic.

*/

using namespace std;

int main () {

    priority_queue<string, vector<string>, greater<>> p_queue;

    p_queue.push("Milo");
    p_queue.push("Zeppelin");
    p_queue.push("Manzo");
    p_queue.push("Zorpis");
    p_queue.push("Dingbat");
    
    while(!p_queue.empty())
    {
        cout << p_queue.top() << endl;
        p_queue.pop();
    }

    return 0;
}