#include <iostream>
#include <iomanip>

/*
    Banking program that allows for depositing, withdrawing, 
    and showing a balance.
*/

using namespace std;

void show_balance(double balance);
double deposit();
double withdraw(double balance);

int main () {

    double balance = 0.0;
    int choice = 0;

    do {
        cout << "\nBANK PROGRAM 9000\n" << endl;
        cout << "Enter your choice: \n";
        cout << "****************** \n";
        cout << "1. Show balance\n";
        cout << "2. Deposit money\n";
        cout << "3. Withdraw money\n";
        cout << "4. Exit\n" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                show_balance(balance);
                break;
            case 2:
                balance += deposit();
                show_balance(balance);
                break;
            case 3:
                balance -= withdraw(balance);
                show_balance(balance);
                break;
            case 4:
                cout << "Thanks for banking with Schlomo Shekelstein :)\n" << endl;

                break;
            default:
                cout << "Sowwy, invalid input uwu :0";
                break;
        }
    } while(choice != 4);

    return 0;
}

void show_balance(double balance) {
    if (balance < 1 && balance > 0) {
        cout << "\nYou have " << setprecision(2) << balance << " cents in ur account\n" << endl;
    }
    else {
        cout << "\nYou have " << fixed << showpoint << setprecision(2) << balance << " dollars in ur account\n" << endl;
    }
}

double deposit() {
    double amount = 0.0;

    cout << "Enter the deposit amount: \n";
    cin >> amount;

    if (amount > 0) {
        return amount;
    }
    else {
        cout << "uwu that's not a valid number :(\n";
        return 0;
    }   
}

double withdraw(double balance) {
    double amount = 0.0;
    
    cout << "Enter the withdrawal amount: \n";
    cin >> amount;

    if (amount > 0 && amount < balance) {
        return amount;
    }
    else if (amount > balance) {
        cout << "You don't have enough money zaddy :(\n";
        return 0;
    }
    else {
        cout << "uwu that's not a valid number :(\n";
        return 0;
    }
}