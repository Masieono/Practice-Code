#include <iostream>
#include <ctime>

/*
    You choose rock, paper, or scissors.
    The computer randomly chooses one as well.

    Then, a victor is determined.
*/

using namespace std;

char get_user_choice();
char get_computer_choice();
void show_choice(char choice);
void choose_winner(char player, char computer);

int main () {

    char player;
    char computer;

    player = get_user_choice();
    cout << "Your choice is ";
    show_choice(player);

    computer = get_computer_choice();
    cout << "Computer's choice is ";
    show_choice(computer);

    choose_winner(player, computer);

    return 0;
}

char get_user_choice() {

    char player;
    cout << "ROCK PAPER SCISSORS 9000\n" << endl;

    do {    
        cout << "R for rock, P for paper, S for scissors\n" << endl;
        cin >> player;
    } while (player != 'R' && player != 'P' && player != 'S');

    return player;
}
char get_computer_choice() {

    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1:
            return 'R';
        case 2:
            return 'P';
        case 3:
            return 'S';
    }
    return 0;
}
void show_choice(char choice) {
    switch (choice) {
        case 'R':
            cout << "Rock" << endl;
            break;
        case 'P':
            cout << "Paper" << endl;
            break;
        case 'S':
            cout << "Scissors" << endl;
            break;
        default:
            cout << "Invalid input zaddy :(" << endl;
            break;
    }
}
void choose_winner(char player, char computer) {

    switch (player) {
        case 'R':
            if (computer == 'R') {
                cout << "It is a tie...for now" << endl;
            }
            else if (computer == 'P') {
                cout << "You lose because you suck" << endl;
            }
            else {
                cout << "You have bested a computer, good job" << endl;
            }
            break;
        case 'P':
            if (computer == 'R') {
                cout << "You've won, it's finally over." << endl;
            }
            else if (computer == 'P') {
                cout << "You tied, nothing special." << endl;
            }
            else {
                cout << "You have lost. To a computer." << endl;
            }
            break;
        case 'S':
            if (computer == 'R') {
                cout << "Your scissors are now crushed" << endl;
            }
            else if (computer == 'P') {
                cout << "You won out of sheer intellect and courage" << endl;
            }
            else {
                cout << "It's a tie, you definitely did not win." << endl;
            }
            break;
    }




}