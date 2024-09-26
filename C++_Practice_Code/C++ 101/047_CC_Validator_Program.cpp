#include <iostream>

/*
    Program to validate a credit card number
    using the "Luhn Algorithm"

    Modifications have been made from the tutorial video
    to make main() as minimal as possible, as well as to
    pratice the compartmentilization of code.

    When functions are fully declared above main(), they 
    must still be declared in a sequence that can be compiled.
    
    sum_even_digits() and sum_odd_digits() must be declared
    before validate() because they are used in validate()

    With function declarations, this is not necessary, but function
    declarations must constantly be updated.
*/

using namespace std;

string get_card_number()
{
    string card_number;
    cout << "Enter a credit card number: " << endl;
    cin >> card_number;

    return card_number;
}

int get_digit(const int number)
{
    return number % 10 + (number / 10 % 10);
}

int sum_odd_digits(const string card_number)
{
    int sum = 0;

    for(int i = card_number.size() - 1; i >= 0; i-=2)
    {
        sum += get_digit(card_number[i] - '0');
    }

    return sum;
}

int sum_even_digits(const string card_number)
{
    int sum = 0;

    for(int i = card_number.size() - 2; i >= 0; i -= 2)
    {
        sum += get_digit((card_number[i] - '0') * 2);
    }

    return sum;
}

bool validate(const string card_number)
{
    int result = sum_even_digits(card_number) + sum_odd_digits(card_number);

    if(result % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

void print_validation(const string card_number, bool is_validated)
{
    if(is_validated)
    {
        cout << card_number << " is a valid credit card" << endl;    
    }
    else 
    {
        cout << card_number << " is not a valid credit card" << endl;
    }
}

int main ()
{
    string card_number = get_card_number();
    print_validation(card_number, validate(card_number));
    return 0;
}