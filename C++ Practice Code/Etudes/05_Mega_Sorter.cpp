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

bool is_valid_number(const std::string& string)
{
    if (string.empty()) return false;

    for (char ch : string)
    {
        if (!std::isdigit(ch))
        {
            return false;
        }
    }

    return true;
}

int get_size()
{
    cout << "A random set of integers will be generated" << endl;
    cout << "Please input how many numbers you would like to sort: ";

    std::string input;
    int size = 0;

    while (true)
    {
        std::getline(std::cin, input);

        if (is_valid_number(input))
        {
            size = std::stoi(input);
            if (size > 0) break;
        }

        cout << "Invalid input. Please try again: ";
    }

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

    cout << result << endl;
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
    cout << "complete!" << endl << endl;
    // print_array(random_array);

    return random_array;
}

void ascending_bubble_sort(const std::vector<int>& input)
{
    cout << "Starting ascending bubble sort. ";
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

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
}

void descending_bubble_sort(const std::vector<int>& input)
{
    cout << "Starting descending bubble sort. ";
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

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
}

void ascending_selection_sort(const std::vector<int>& input)
{

    cout << "Starting ascending selection sort. ";
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

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
}

void descending_selection_sort(const std::vector<int>& input)
{
    cout << "Starting descending selection sort. ";
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

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
}

void ascending_insertion_sort(const std::vector<int>& input)
{
    cout << "Starting ascending insertion sort. ";
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

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

}

void descending_insertion_sort(const std::vector<int>& input)
{
    cout << "Starting descending insertion sort. ";
    std::vector<int> sorted_array = input;

    auto start_time = std::chrono::high_resolution_clock::now();

    for(int i = 1; i < sorted_array.size(); i++)
    {
        int temp = sorted_array[i];
        int j = i - 1;

        while(j >= 0 && sorted_array[j] < temp)
        {
            sorted_array[j + 1] = sorted_array[j];
            j--;
        }
        sorted_array[j + 1] = temp;
    }


    auto end_time = std::chrono::high_resolution_clock::now();

    cout << "Complete. ";
    cout << "Time to complete: ";
    print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));
}

void ascending_merge(const std::vector<int>& left_array, const std::vector<int>& right_array, std::vector<int>& array)
{
    int left_size = left_array.size();
    int right_size = right_array.size();
    int i = 0, l = 0, r = 0; //indices

    while(l < left_size && r < right_size)
    {
        if(left_array[l] < right_array[r])
        {
            array[i] = left_array[l];
            l++;
        }
        else
        {
            array[i] = right_array[r];
            r++;
        }
        i++;
    }
    while (l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }
    while(r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}

void ascending_merge_sort(std::vector<int>& input)
{
    int length = input.size();
    if (length <= 1) return;    //base case

    int middle = length / 2;
    std::vector<int> left_array(input.begin(), input.begin() + middle);
    std::vector<int> right_array(input.begin() + middle, input.end());

    ascending_merge_sort(left_array);
    ascending_merge_sort(right_array);
    ascending_merge(left_array, right_array, input);
}

void descending_merge(const std::vector<int>& left_array, const std::vector<int>& right_array, std::vector<int>& array)
{
    int left_size = left_array.size();
    int right_size = right_array.size();
    int i = 0, l = 0, r = 0;

    while ( l < left_size && r < right_size)
    {
        if (left_array[l] > right_array[r])
        {
            array[i] = left_array[l];
            l++;
        }
        else
        {
            array[i] = right_array[r];
            r++;
        }
        i++;
    }

    // copy remaining elements of left_array, if any
    while ( l < left_size)
    {
        array[i] = left_array[l];
        i++;
        l++;
    }

    // copy remaining elements of right_array, if any
    while(r < right_size)
    {
        array[i] = right_array[r];
        i++;
        r++;
    }
}

void descending_merge_sort(std::vector<int>& input)
{
    int length = input.size();
    if (length <= 1) return; // Base case

    int middle = length / 2;
    std::vector<int> left_array(input.begin(), input.begin() + middle);
    std::vector<int> right_array(input.begin() + middle, input.end());    

    descending_merge_sort(left_array);
    descending_merge_sort(right_array);

    descending_merge(left_array, right_array, input);
}

int ascending_partition(std::vector<int>& input, int start, int end)
{
    int pivot = input[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++)
    {
        if(input[j] < pivot)
        {
            i++;
            std::swap(input[i], input[j]);
        }
    }
    i++;
    std::swap(input[i], input[end]);

    return i;

}

void ascending_quick_sort(std::vector<int>& input, int start, int end)
{
    if (end <= start) return;   // base case

    int pivot = ascending_partition(input, start, end);
    ascending_quick_sort(input, start, pivot - 1);
    ascending_quick_sort(input, pivot + 1, end);
}

int descending_partition(std::vector<int>& input, int start, int end)
{
    int pivot = input[end];
    int i = start - 1;

    for(int j = start; j <= end - 1; j++)
    {
        if(input[j] > pivot)
        {
            i++;
            std::swap(input[i], input[j]);
        }
    }
    i++;
    std::swap(input[i], input[end]);

    return i;
}

void descending_quick_sort(std::vector<int>& input, int start, int end)
{
    if (end <= start) return;   // base case
    
    int pivot = descending_partition(input, start, end);
    descending_quick_sort(input, start, pivot - 1);
    descending_quick_sort(input, pivot + 1, end);
}

void max_heapify(std::vector<int>& input, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && input[left] > input[largest]) largest = left;
    if (right < n && input[right] > input[largest]) largest = right;
    if (largest != i)
    {
        std::swap(input[i], input[largest]);

        max_heapify(input, n, largest);
    }
}

void ascending_heap_sort(std::vector<int>& input)
{
    int n = input.size();

    for(int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(input, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(input[0], input[i]);

        max_heapify(input, i, 0);
    }
}

void min_heapify(std::vector<int>& input, int n, int i)
{
    int smallest = i;       // initialize smallest as root
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // if left child is smaller than root
    if (left < n && input[left] < input[smallest]) smallest = left;
    // if right child is smaller than root
    if (right < n && input[right] < input[smallest]) smallest = right;

    // if smallest is not root
    if (smallest != i)
    {
        std::swap(input[i], input[smallest]);

        // recursively heapify the affected subtree
        min_heapify(input, n, smallest);
    }
}

void descending_heap_sort(std::vector<int>& input)
{
    int n = input.size();

    // build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        min_heapify(input, n, i);
    }

    // extract elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        // move current root to the end
        std::swap(input[0], input[i]);

        // call min heapify on reduced heap
        min_heapify(input, i, 0);
    }
}

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
        descending_insertion_sort(original_array);


        cout << "Starting ascending merge sort. ";    
        std::vector<int> copied_array = original_array;
        auto start_time = std::chrono::high_resolution_clock::now();
        ascending_merge_sort(copied_array);    
        auto end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));


        cout << "Starting descending merge sort. ";
        copied_array = original_array;
        start_time = std::chrono::high_resolution_clock::now();
        descending_merge_sort(copied_array);
        end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));


        cout << "Starting asscending quick sort. ";
        copied_array = original_array;
        start_time = std::chrono::high_resolution_clock::now();
        ascending_quick_sort(copied_array, 0, copied_array.size() - 1);
        end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));


        cout << "Starting descending quick sort. ";
        copied_array = original_array;
        start_time = std::chrono::high_resolution_clock::now();
        descending_quick_sort(copied_array, 0, copied_array.size() - 1);
        end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));


        cout << "Starting ascending heap sort. ";
        copied_array = original_array;
        start_time = std::chrono::high_resolution_clock::now();
        ascending_heap_sort(copied_array);
        end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));


        cout << "Starting descending heap sort. ";
        copied_array = original_array;
        start_time = std::chrono::high_resolution_clock::now();
        descending_heap_sort(copied_array);
        end_time = std::chrono::high_resolution_clock::now();
        cout << "Complete. ";
        cout << "Time to complete: ";
        print_duration(std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time));

        running = ask_to_go_again();
    }
    outtro_message();
    return 0;
}