#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int currentPlayer = 1; // 1 for Player X, 2 for Player O

void displayBoard()
{
    cout << "T I C K -- T A C -- T O E -- G A M E\n";
    cout << "Player 1 [X]    Player 2 [O]\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "     |     |     \n";
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << " \n";
        cout << "_____|_____|_____\n";
    }
    cout << "     |     |     \n";
}

bool isValidMove(int choice)
{
    return (choice >= 1 && choice <= 9 && board[(choice - 1) / 3][(choice - 1) % 3] != 'X' && board[(choice - 1) / 3][(choice - 1) % 3] != 'O');
}

void makeMove(int choice)
{
    char symbol = (currentPlayer == 1) ? 'X' : 'O';
    board[(choice - 1) / 3][(choice - 1) % 3] = symbol;
    currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch players
}

bool checkWin()
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return true;
    }

    return (board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
           (board[0][2] == board[1][1] && board[1][1] == board[2][0]);
}

bool isBoardFull()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

int main()
{
    int choice;

    while (true)
    {
        displayBoard();
        cout << "Player " << currentPlayer << " turn. Enter a number (1-9): ";
        cin >> choice;

        if (!isValidMove(choice))
        {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        makeMove(choice);

        if (checkWin())
        {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull())
        {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
