// Write a method Boolean isKingSafe(int[][]chessBoard)
// Returns true if king in the given chess board is safe from the given enemies otherwise false;
// NOTE: Enemies are- Horse, Camel, Queen, Elephant only
// Do not consider the colour case of the chess board for traversal of camel and all.

#include <bits/stdc++.h>
using namespace std;

bool isSafeFromHorse(vector<vector<char>> board, int i, int j)
{
    int row[8] = {2, 2, -1, 1, -1, 1, -2, -2};
    int col[8] = {-1, 1, 2, 2, -2, -2, -1, 1};

    for (int index = 0; index < 8; index++)
    {
        int n_row = i + row[index];
        int n_col = j + col[index];
        if (n_row < 0 || n_col < 0 || n_row > 8 || n_col > 8)
        {
            continue;
        }
        else
        {
            if (board[n_row][n_col] == 'K')
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafeFromCamel(vector<vector<char>> board, int i, int j)
{
    int row = i;
    int col = j;
    i--;
    j++;
    while (i >= 0 && j < 8)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i--;
        j++;
    }

    i = row;
    j = col;
    i++;
    j--;
    while (i < 8 && j >= 0)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i++;
        j--;
    }

    i = row;
    j = col;
    i--;
    j--;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i--;
        j--;
    }

    i = row;
    j = col;
    i++;
    j++;
    while (i < 8 && j < 8)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i++;
        j++;
    }
    return true;
}

bool isSafeFromElephant(vector<vector<char>> board, int i, int j)
{
    int row = i;
    int col = j;
    i--;
    while (i >= 0)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i--;
    }
    i = row;
    i++;
    while (i < 8)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        i++;
    }
    i = row;
    j--;
    while (j >= 0)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        j--;
    }
    j = col;
    j++;
    while (j < 8)
    {
        if (board[i][j] == 'K')
        {
            return false;
        }
        j++;
    }
    return true;
}

bool isKingSafe(vector<vector<char>> board)
{
    bool queen, horse, camel, elephant;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == 'Q')
            {
                if (!(isSafeFromElephant(board, i, j) && isSafeFromHorse(board, i, j)))
                {
                    return false;
                }
            }
            else if (board[i][j] == 'H')
            {
                if (!isSafeFromHorse(board, i, j))
                {
                    return false;
                }
            }
            else if (board[i][j] == 'C')
            {
                if (!isSafeFromCamel(board, i, j))
                {
                    return false;
                }
            }
            else if (board[i][j] == 'E')
            {
                if (!isSafeFromElephant(board, i, j))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<char>> board = {
        {'E', 'H', 'C', 'Q', 'K', 'C', 'H', 'E'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'E', 'H', 'C', 'Q', '.', 'C', 'H', 'E'}};

    if (isKingSafe(board))
    {
        cout << "The king is safe" << endl;
    }
    else
    {
        cout << "King is not safe" << endl;
    }

    return 0;
}