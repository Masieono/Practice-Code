#include <iostream>
#include <list>
#include <vector>
#include <chrono>

/*
    The same as previous lesson, 
    but utilizing a lambda function 
    to reduce the amount of redundant 
    timing code.
*/

using namespace std;
using namespace chrono;

void display_time_delta(const system_clock::time_point& start_time, const chrono::system_clock::time_point& end_time)
{
    //auto duration = duration_cast<milliseconds>(end_time - start_time);
    duration<double, milli> duration = end_time - start_time;

    if(duration.count() < 1000)
    {
        cout << "it took " << duration.count() << " milliseconds.\n";
    }
    else if(duration.count() < 60000)
    {
        int seconds = static_cast<int>(duration.count() / 1000);
        int milliseconds = static_cast<int>(duration.count()) % 1000;
        cout << "it took " << seconds << " seconds and " << milliseconds << "milliseconds.";   
    }
    else if(duration.count() < 3600000)
    {
        int minutes = static_cast<int>(duration.count() / 60000);
        int seconds = static_cast<int>(duration.count() / 1000);
        int milliseconds = static_cast<int>(duration.count()) % 1000;
        cout << "it took " << minutes << " minutes, " << seconds << " seconds, and " << milliseconds << " milliseconds.";
    }
    else
    {
        cout << "That shit took me over an hour :(\n";    
    }
}

template <typename Function>
void measure_and_display_time (Function func, const string& message)
{
    auto start_time = system_clock::now();
    func();
    auto end_time = system_clock::now();
    cout << message;
    display_time_delta(start_time, end_time);
}

template <typename Container>
bool find_num (const Container& container, int target)
{
    for (const int& value : container)
    {
        if (value == target) return true;
    }

    return false;
}

template <typename Container>
void insert_num (Container& container, int target, int position)
{
    auto it = container.begin();
    advance(it, position);
    container.insert(it, target);
}

template <typename Container>
void erase_num (Container& container, int position)
{
    auto it = container.begin();
    advance(it, position);
    container.erase(it);
}

template <typename Container>
void double_container_contents(Container& container)
{
    auto it = container.begin();
    while (it != container.end())
    {
        *it *= 2;
        it++;
    }
}

int get_user_num()
{
    int num;
    cout << "Enter a number between one and a million: ";
    cin >> num;

    return num;
}

void outtro()
{
    cout << "\n\n\nthank u for ur time\n\n\n";
}

bool ask_to_go_again()
{
    char input;
    cout << "Would you like to run another test? y/n" << endl;
    cin >> input; cin.ignore();
    return (input == 'Y' | input == 'y');
}

void print_sizes(const list<int>& list, const vector<int>& vector)
{
    cout << endl;
    cout << "Size of list: " << list.size() << endl;
    cout << "Size of vector: " << vector.size() << endl;
}

int main () {

    vector<int> my_vector;
    list<int> my_list;

    for (int i = 0; i < 1000000; i++)
    {
        my_list.push_back(i);
        my_vector.push_back(i);
    }
    cout << "\n***list and vector loaded***\n";

    bool running = true;
    while(running)
    {

        int num = get_user_num();

        measure_and_display_time([&]()
        {
            if (find_num(my_list, num))
            {
                cout << "List entry was valid, ";
            }
            else {
                cout << "List entry was invalid, ";
            }
        }, "");

        measure_and_display_time([&]()
        {
            insert_num(my_list, num, num);
            cout << "Insert was succesful, ";
        }, "");

        measure_and_display_time([&]()
        {
            erase_num(my_list, num);
            cout << "Erasure was successful, ";
        }, "");

        measure_and_display_time([&]()
        {
            double_container_contents(my_list);
            cout << "Container doubling successful, ";
        }, "");

        cout << endl;

        measure_and_display_time([&]()
        {
            if (find_num(my_vector, num))
            {
                cout << "Vector entry was valid, ";
            }
            else {
                cout << "Vector entry was invalid, ";
            }
        }, "");

        measure_and_display_time([&]()
        {
            insert_num(my_vector, num, num);
            cout << "Insert was successful, ";
        }, "");

        measure_and_display_time([&]()
        {
            erase_num(my_vector, num);
            cout << "Erasure was successful, ";
        }, "");

        measure_and_display_time([&]()
        {
            double_container_contents(my_vector);
            cout << "Container double successful, ";
        }, "");

        print_sizes(my_list, my_vector);

        cout << endl;
        running = ask_to_go_again();
    }

    outtro();

    return 0;
}
