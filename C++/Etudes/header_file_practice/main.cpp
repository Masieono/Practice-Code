#include <iostream>
#include "includes/header_example.hpp"

/*
    common #include convention is to use
    - angle brackets for the standard or commonly used libraries
    - quotation marks for locally sourced libraries that are your own

    no other functions exist within the main file
    everything is called from elsewhere
*/

int main (){

    bool running = true;
        
    while(running)
    {
        int x = get_num_one();
        int y = get_num_two();
        int sum = add_2_nums(x, y);
        print_sum(sum);

        std::vector<std::string> message = get_text();
        print_message(message);

        running = prompt_to_go_again();
    }

    outtro_sequence();

    return 0;
}
