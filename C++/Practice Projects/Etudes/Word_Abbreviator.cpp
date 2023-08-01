#include <iostream>
#include <unordered_map>

/*
    Starts with a series of words and their abbreviations

    User is able to add more words and abbreviations to the list, 
    search for any word or abbreviation to see it's partner,
    and print the entire list to the terminal.
*/

using namespace std;

int main () {

    unordered_map<string, string> full_colors = 
    {
        {"black", "blk"},
        {"white", "wht"},
        {"red", "red"},
        {"green", "grn"},
        {"blue", "blu"},
        {"yellow", "ylo"},
    };



    return 0;
}