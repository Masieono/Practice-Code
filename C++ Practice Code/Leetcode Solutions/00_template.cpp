#include <iostream>


/*

*/


bool ask_to_go_again()
{
    char input;
    cout << "Would you like to do this again? Y or N" << endl;

    while(true)
    {
        std::cin >> input;
        std::cin.ignore(1000, '\n');

        if (input == 'Y' || input == 'y') return true;
        else if (input == 'N' || input == 'n') return false;
        else std::cout << "Invalid input. Please try again: ";
    }
}

int main()
{
    std::cout << "Program starting." << std::endl;

    bool running = true;

    while (running)
    {



        running = ask_to_go_again();
    }

    std::cout << "Program ending." << std::endl;
    return 0;
}