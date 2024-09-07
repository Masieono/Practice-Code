#include <iostream>
#include <vector>

//^ prevents the file from being included multiple times in compilation

/*
    This is the header file, as seen by the '.h' extension
    .h files will work with programs written in C or C++
    .hpp files will only work with programs written in C
    otherwise, they are interchangeable

    The header file contains function declarations, without 
    the 'guts' of the function. This is to denote the functionality 
    and use-cases of each function for users of the library,
    without having to divulge the methods used in the functions.

    There is no int main()
*/

int get_num_one();

int get_num_two();

int add_2_nums(int x, int y);

void print_sum(int sum);

std::vector<std::string> get_text();

void print_message(const std::vector<std::string>& message);

bool prompt_to_go_again();

void outtro_sequence();