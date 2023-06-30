#include <stdio.h>
#include <string.h>

/*
    The string library allows for various text manipulation.
    Changing text case, replacing characters, reversing text, ect.
*/


int main() {

    char string1[] = "Firstname";
    char string2[] = "Lastname";

    // The following are a few text manipulation functions

    strlwr(string1); // converts string to lower case
    strupr(string2); // converts string to upper case
    strcat(string1, string2); // appends string2 to end of string1
    strcpy(string1, string2); // copy string2 to string1
    strncpy(string1, string2, 4); // copy n characters of string2 to string1
    strrev(string1); // reverse a string

    // The following are functions that return an integer

    int result = strlen(string2); // returns the length of the string as an int
    int result = strcmp(string1, string2); // compares all characters in a string (0 means exact match)
    int result = strcmpi(string1, string2); // compares all characters, case insensitive
    int result = strnicmp(string1, string2, 4); // compares first n characters, case insensitive

    printf("%s", string1);

    return 0;
}