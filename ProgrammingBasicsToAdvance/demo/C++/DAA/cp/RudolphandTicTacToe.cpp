#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a player has a winning configuration
bool hasWon(char player, const vector<string> &board)
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
        {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

string findWinner(const vector<string> &board)
{

    if (hasWon('X', board))
    {
        return "X";
    }
    else if (hasWon('O', board))
    {
        return "O";
    }
    else if (hasWon('+', board))
    {
        return "+";
    }
    else
    {
        return "DRAW";
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<string> board(3);

        for (int j = 0; j < 3; j++)
        {
            cin >> board[j];
        }

        string result = findWinner(board);
        cout << result << endl;
    }

    return 0;
}
