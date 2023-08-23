#include <iostream>
#include <stack>

/*
    Stack is a last in, first out data structure. 
    Like a stack of books or CDs where you can only see
    the top item. You have to remove the top item to see
    the second-most top item.

    push() to add to the top of stack
    pop() to remove from top of stack
    size() to get the number of contents within stack
    empty() returns a boolean, true if the stack is empty
    top() returns a copy of the value on top of the stack

    Typically not the best solution when you need to 
    iterate through values a lot. There is no easy access
    to the middle of the stack without creating a new 
    stack or data structure.

    Particularly useful for undo/redo features, 
    back/forward buttons on browser history,
    backtracking algorithms (maze, file directories)



*/

using namespace std;

void print_reverse_stack(const stack<string> &original_stack)
{
    stack<string> temp_stack = original_stack;
    //temp stack is needed to access all values

    cout << "Stack in reverse order: " << endl;

    while (!temp_stack.empty())
    {
        cout << temp_stack.top() << endl;
        temp_stack.pop();
    }

    cout << endl;
}

void print_stack(const stack<string> &original_stack)
{
    stack<string> operating_stack = original_stack;
    stack<string> temp_stack;

    cout << "Stack in order: " << endl;

    while (!operating_stack.empty())
    {
        temp_stack.push(operating_stack.top());
        operating_stack.pop();
    }
    
    while (!temp_stack.empty())
    {
        cout << temp_stack.top() << endl;
        temp_stack.pop();
    }

    cout << endl;
}

int main () {

    stack<string> my_viddygames;

    my_viddygames.push("BOTW");
    my_viddygames.push("TOTK");
    my_viddygames.push("Picross 7");
    my_viddygames.push("Kirby");
    my_viddygames.push("Smash Bros");
    //"stacking" games on top of one another, starting with BOTW.

    cout << "Size of the stack: " << my_viddygames.size() << endl;

    print_stack(my_viddygames);

    print_reverse_stack(my_viddygames);    



    return 0;
}