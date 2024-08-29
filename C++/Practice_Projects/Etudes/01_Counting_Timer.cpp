#include <iostream>
#include <chrono>

/*
    The computer asks the user to pick a number,
    and then counts to that number by printing 
    each number to the console starting at 0.

    Once the count has finished, the program 
    calculates how long it took to count to the 
    user inputted number.
*/

using namespace std;
using namespace chrono;

void intro_sequence()
{
    cout << "\n\n\nWelcome to counter-timer 9000" << endl;
    cout << "I will ask you for a number, " << endl;
    cout << "and then count to that number." << endl;
    cout << "\nI will even tell you how long it took me.\n";
}

bool ask_to_play_again()
{
    cout << "Would you like to do this whole thing again?" << endl;
    char input;
    cin >> input;
    cin.ignore();
    return(input == 'Y' || input == 'y');
}

int ask_for_number()
{
    cout << "\nPlease enter a number for me to count to: \n";
    int num;
    cin >> num;

    return num;
}

void display_time_delta(const system_clock::time_point& start_time, const chrono::system_clock::time_point& end_time)
{
    //auto duration = duration_cast<milliseconds>(end_time - start_time);
    duration<double, milli> duration = end_time - start_time;

    cout << "\nThe counting has finished.\nMy job is complete.\n";

    if(duration.count() < 1000)
    {
        cout << "It only took me " << duration.count() << " milliseconds.\n\n";
    }
    else if(duration.count() < 60000)
    {
        int seconds = static_cast<int>(duration.count() / 1000);
        int milliseconds = static_cast<int>(duration.count()) % 1000;
        cout << "It only took me " << seconds << " seconds and " << milliseconds << "milliseconds.\n";   
    }
    else if(duration.count() < 3600000)
    {
        int minutes = static_cast<int>(duration.count() / 60000);
        int seconds = static_cast<int>(duration.count() / 1000);
        int milliseconds = static_cast<int>(duration.count()) % 1000;
        cout << "It only took me " << minutes << " minutes, " << seconds << " seconds, and " << milliseconds << " milliseconds.\n";
    }
    else
    {
        cout << "That shit took me over an hour :(\n";    
    }

}

int main () {

    intro_sequence();

    bool running = true;
    while(running)
    {
        int number = ask_for_number();

        auto start_time = system_clock::now();

        for(int i = 0; i <= number; i++)
        {
            cout << i;
            if(i < number)
            {
                cout << ", ";
            }
        }

        auto end_time = chrono::system_clock::now();

        display_time_delta(start_time, end_time);

        running = ask_to_play_again();
    }


    return 0;
}