#include <iostream>
#include <vector>

/*

    You are given an array prices[] where prices[i] 
    is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a 
    single day to buy one stock and choosing a 
    different day in the future to sell that stock.

    Return the maximum profit you can achieve from 
    this transaction. 
    
    If you cannot achieve any profit, return 0.


    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.

*/

void print_vector(std::vector<int> vector)
{
    for (int num : vector)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int max_profit(std::vector<int>& prices)
{
    int max_profit = 0;             // returns 0 if no profit can be achieved
    int minimum_price = prices[0];  // smallest price, initialized on first day's price

    // iterate through every day of price action
    for (int i = 0; i < prices.size(); i++)
    {
        // building up a minimum price, gets re-written whenever a lower price is found
        if (i > 0 && prices[i] < minimum_price)
        {
            minimum_price = prices[i];
        }

        max_profit = std::max(max_profit, prices[i] - minimum_price);
    }

    std::cout << "Max profit: " << max_profit << std::endl;

    return max_profit;
}

bool ask_to_go_again()
{
    char input;
    std::cout << "Would you like to do this again? Y/N" << std::endl;

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
        std::vector<int> testCase01, testCase02;
        testCase01.push_back(7);
        testCase01.push_back(1);
        testCase01.push_back(5);
        testCase01.push_back(3);
        testCase01.push_back(6);
        testCase01.push_back(4);
        
        testCase02.push_back(7);
        testCase02.push_back(6);
        testCase02.push_back(4);
        testCase02.push_back(3);
        testCase02.push_back(1);

        print_vector(testCase01);
        print_vector(testCase02);
        
        max_profit(testCase01);
        max_profit(testCase02);

        std::cout << std::endl;

        running = ask_to_go_again();
    }

    std::cout << "Program ending." << std::endl;
    return 0;
}