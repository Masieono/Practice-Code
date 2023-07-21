#include <iostream>
#include <random>

/*
    A tic tac toe game
*/

using namespace std;

void draw_board(char *spaces)
{
    cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "-----|-----|-----" << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    cout << endl;

}

void player_move(char *spaces, char player)
{
    int number;
    do {
        cout << "enter a spot to place an X (1-9)" << endl;
        cin >> number;
        number--;

        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
    }while(!number > 0 || !number < 8);
}

void computer_move(char *spaces, char player, char computer)
{
    int number;
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> random_roll(0, 8);

    while(true)
    {
        number = random_roll(generator);
        if(spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool check_winner(char *spaces, char player, char computer)
{
    if(spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2])
    {
        spaces[0] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5])
    {
        spaces[3] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8])
    {
        spaces[6] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6])
    {
        spaces[0] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }    
    else if(spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7])
    {
        spaces[1] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8])
    {
        spaces[2] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8])
    {
        spaces[0] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else if(spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6])
    {
        spaces[2] == player ? cout << "YOU WIN" << endl : cout << "YOU LOSE" << endl;
    }
    else
    {
        return false;
    }
    return true;
}

bool check_tie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a tie :(" << endl;
    return true;
}

int main () {

    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    draw_board(spaces); 
    //when passing an array to a function, it decays to a pointer

    while(running)
    {
        player_move(spaces, player);
        draw_board(spaces);
        if(check_winner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if(check_tie(spaces))
        {
            running = false;
            break;
        }

        computer_move(spaces, player, computer);
        draw_board(spaces);
        if(check_winner(spaces, player, computer))
        {
            running = false;
            break;
        }
        else if(check_tie(spaces))
        {
            running = false;
            break;
        }
    }

    cout << "\n Thanks for playing" << endl;

    return 0;
}