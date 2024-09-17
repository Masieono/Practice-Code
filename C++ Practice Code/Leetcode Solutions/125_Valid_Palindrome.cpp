#include <iostream>



using std::cout;
using std::endl;

std::string get_user_string()
{
    std::string input;
    cout << "Please input string: " << endl;
    std::getline(std::cin, input);

    return input;
}

bool is_palindrome(std::string input)
{
    int first = 0;
    int last = input.size() - 1;

    while (first < last)
    {
        if (!isalnum(input[first])) 
        {
            first++;
            continue;
        }
        if (!isalnum(input[last]))
        {
            last--;
            continue;
        }
        if(tolower(input[first]) != tolower(input[last]))
        {
            return false;
        }
        else
        {
            first++;
            last--;
        }
    }
    return true;
}

int main ()
{
    std::string input = get_user_string();

    cout << ((is_palindrome(input)) ? "Certified Palindrome" : "Not a palindrome unfortunately") << endl;

    return 0;
}