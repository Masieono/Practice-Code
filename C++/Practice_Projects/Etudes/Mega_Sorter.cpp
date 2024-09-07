#include <iostream>
#include <vector>
#include <chrono>       // for benchmarking speeds
#include <random>       // std::random_device and std::mt19937
#include <algorithm>    // std::shuffle

/*
    Displays all types of sorting algorithms, and tests each one for their speed.

    User inputs a number, that number becomes the size of a generated array.
    The array is shuffled randomly and used for sorting algos.

    Each sorting algo copies the array, sorts it appropriately, and prints how long it took.

    Sorting algos offered in both ascending and descending variants:

    O(n^2) Quadratic
        Bubble sort
        Selection sort
        Insertion sort

    0(n log n) Quasilinear 
        Merge sort
        Quick sort
        Heap sort
*/

using std::cout;
using std::endl;
using std::vector;

void intro_message()
{
    cout << "WELCOME TO MEGA SORTER 9000" << endl << endl;
}

int get_size()
{
    cout << "A random set of integers will be generated" << endl;
    cout << "Please input how many numbers you would like to sort: ";

    int size = 0;
    std::cin >> size;

    cout << "You have chosen the array size of " << size << endl;

    return size;
}

void print_array(vector<int>& input)
{
    for(int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
    }
    cout << endl << endl;
}

void print_duration(std::chrono::milliseconds duration)
{
    //calculate the time in minutes/seconds/milliseconds    
    std::chrono::minutes minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
    std::chrono::seconds seconds = std::chrono::duration_cast<std::chrono::seconds>(duration) % 60;
    std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration) %1000;

    //format the time into the most appropriate printout
    std::string result;

    if (minutes.count() > 0)
    {
        result += std::to_string(minutes.count()) + " minute" + (minutes.count() > 1 ? "s" : "");
    }
    if (seconds.count() > 0)
    {
        if (!result.empty())
        {
            result += ", ";
        }
        result += std::to_string(seconds.count()) + " second" + (seconds.count() > 1 ? "s" : "");
    }
    if (milliseconds.count() > 0 || result.empty())
    {
        if (!result.empty())
        {
            result += ", ";
        }
        result += std::to_string(milliseconds.count()) + " millisecond" + (milliseconds.count() > 1 ? "s" : "");
    } 

    cout << result << endl << endl;
}

vector<int> generate_array(int size)
{
    //start with an array of the inputted size
    std::vector<int> random_array(size);

    cout << "Loading array . . . ";

    //populate it with numbers 0 to size
    for(int i = 0; i < size; i++)
    {
        random_array[i] = i + 1;
    }

    //scramble the numbers so the array is out of order
    std::random_device random;
    std::mt19937 g(random());
    std::shuffle(random_array.begin(), random_array.end(), g);

    // print the array to show the scramble and amount of numbers
    cout << "here is your array:" << endl;
    print_array(random_array);

    return random_array;
}

void ascending_bubble_sort(const std::vector<int>& input)
{
    cout << "Starting ascending bubble sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo
    for(int i = 0; i < sorted_array.size(); i++)
    {
        for(int j = 0; j < (sorted_array.size() - i - 1); j++)
        {
            if(sorted_array[j] > sorted_array[j + 1])
            {
                int temp = sorted_array[j];
                sorted_array[j] = sorted_array[j + 1];
                sorted_array[j + 1] = temp;
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending bubble sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    // print_array(sorted_array);
}

void descending_bubble_sort(const std::vector<int>& input)
{
    cout << "Starting descending bubble sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo
    for(int i = 0; i < sorted_array.size(); i++)
    {
        for(int j = 0; j < (sorted_array.size() - i - 1); j++)
        {
            if(sorted_array[j] < sorted_array[j + 1])
            {
                int temp = sorted_array[j];
                sorted_array[j] = sorted_array[j + 1];
                sorted_array[j + 1] = temp;
            }
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending bubble sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    // print_array(sorted_array);
}

void ascending_selection_sort(const std::vector<int>& input)
{

    cout << "Starting ascending selection sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo
    for(int i = 0; i < sorted_array.size(); i++)
    {
        int min = i;

        for(int j = (i +1); j < sorted_array.size() - 1; j++)
        {
            if(sorted_array[min] > sorted_array[j])
            {
                min = j;
            }
        }
        int temp = sorted_array[i];
        sorted_array[i] = sorted_array[min];
        sorted_array[min] = temp;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending selection sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

//    print_array(sorted_array);
}

void descending_selection_sort(const std::vector<int>& input)
{
    cout << "Starting descending selection sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo
    for(int i = 0; i < sorted_array.size() - 1; i++)
    {
        int min = i;

        for(int j = (i +1); j < sorted_array.size(); j++)
        {
            if(sorted_array[min] < sorted_array[j])
            {
                min = j;
            }
        }
        int temp = sorted_array[i];
        sorted_array[i] = sorted_array[min];
        sorted_array[min] = temp;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending selection sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

//    print_array(sorted_array);
}

void ascending_insertion_sort(const std::vector<int>& input)
{
    cout << "Starting ascending insertion sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo
    for(int i = 1; i < sorted_array.size(); i ++)
    {
        int temp = sorted_array[i];
        int j = i - 1;

        while(j >= 0 && sorted_array[j] > temp)
        {
            sorted_array[j + 1] = sorted_array[j];
            j--;
        }
        sorted_array[j + 1] = temp;
    }

    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending insertion sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void descending_insertion_sort(const std::vector<int>& input)
{
    cout << "Starting descending insertion sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo



    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending insertion sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void ascending_merge_sort(const std::vector<int>& input)
{
    cout << "Starting ascending merge sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo




    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending merge sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void descending_merge_sort(const std::vector<int>& input)
{
    cout << "Starting descending merge sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo



    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending merge sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void ascending_quick_sort(const std::vector<int>& input)
{
    cout << "Starting ascending quick sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo



    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending quick sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void descending_quick_sort(const std::vector<int>& input)
{
    cout << "Starting descending quick sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo


    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending quick sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void ascending_heap_sort(const std::vector<int>& input)
{
    cout << "Starting ascending heap sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo


    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Ascending heap sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}

void descending_heap_sort(const std::vector<int>& input)
{
    cout << "Starting descending heap sort." << endl;
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    // actual sort algo



    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Descending heap sort complete." << endl;
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

    print_array(sorted_array);
}


bool ask_to_go_again()
{
    char input;
    cout << "Would you like to do this again? Y or N" << endl;
    std::cin >> input;

    // std::cin.ignore(1000, '\n');

    return(input == 'Y' || input == 'y');
}

void outtro_message()
{
    cout << endl;
    cout << "It's been real, and it's been fun," << endl;
    cout << "but it hasn't been real fun." << endl << endl;
    cout << "Powering off...beep boop" << endl << endl;
}

int main () {

    intro_message();

    bool running = true;
    while(running)
    {
        // get the size of the array from the user, create a jumbled array.
        int array_size = get_size();

        std::vector<int> original_array = generate_array(array_size);

        // sorting algos go here, they copy the original_array to a new array address
        // the new array is sorted so that all sorting algos start from the same jumble
        ascending_bubble_sort(original_array);
        descending_bubble_sort(original_array);

        ascending_selection_sort(original_array);
        descending_selection_sort(original_array);
        
        ascending_insertion_sort(original_array);
    //    descending_insertion_sort(original_array);

    //    ascending_merge_sort(original_array);
    //    descending_merge_sort(original_array);

    //    ascending_quick_sort(original_array);
    //    descending_quick_sort(original_array);

        running = ask_to_go_again();
    }
    outtro_message();
    return 0;
}