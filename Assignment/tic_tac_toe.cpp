#include <bits/stdc++.h>
using namespace std;

// Checking computer's first move
void FirstMove(vector<pair<bool, char>> &arr)
{
    // If center is empty
    if (!arr[4].first)
    {
        arr[4].first = true;
        arr[4].second = 'C';
    }
    else // If corners are empty
    {
        vector<int> corners = {0, 2, 6, 8};
        for (int corner : corners)
        {
            if (!arr[corner].first)
            {
                arr[corner].first = true;
                arr[corner].second = 'C';
                break;
            }
        }
    }
}

bool isWinning(vector<int> current, vector<pair<bool, char>> &arr)
{
    int countC = 0, countU = 0;
    for (int pos : current)
    {
        if (arr[pos].first && arr[pos].second == 'C')
            countC++;
        if (arr[pos].first && arr[pos].second == 'U')
            countU++;
    }
    return countC == 2 || countU == 2;
}

// For placing subsequent moves
void SubsequentMoves(vector<pair<bool, char>> &arr)
{
    // Winning positions
    vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    // Check for a move to win or block the opponent
    for (const auto &pattern : winPatterns)
    {
        if (isWinning(pattern, arr))
        {
            for (int pos : pattern)
            {
                if (!arr[pos].first)
                {
                    arr[pos].first = true;
                    arr[pos].second = 'C';
                    return;
                }
            }
        }
    }

    // Else check for center
    if (!arr[4].first)
    {
        arr[4].first = true;
        arr[4].second = 'C';
        return;
    }

    // Else check for corners
    vector<int> corners = {0, 2, 6, 8};
    for (int corner : corners)
    {
        if (!arr[corner].first)
        {
            arr[corner].first = true;
            arr[corner].second = 'C';
            return;
        }
    }

    // Else pick any empty space
    for (int i = 0; i < 9; i++)
    {
        if (!arr[i].first)
        {
            arr[i].first = true;
            arr[i].second = 'C';
            return;
        }
    }
}

// Function to display the current status
void display(vector<pair<bool, char>> &arr, vector<vector<char>> &grid)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i].first)
        {
            int row = i / 3;
            int col = i % 3;
            grid[row][col] = arr[i].second;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }

    cout << endl;
}

int IsWinner(vector<pair<bool, char>> &arr)
{
    vector<vector<int>> winPatterns = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};

    for (const auto &pattern : winPatterns)
    {
        int countC = 0, countU = 0;
        for (int pos : pattern)
        {
            if (arr[pos].first && arr[pos].second == 'C')
                countC++;
            if (arr[pos].first && arr[pos].second == 'U')
                countU++;
        }
        if (countC == 3)
            return 1; // Computer wins
        if (countU == 3)
            return 2; // User wins
    }
    return -1; // No winner yet
}

int main()
{
    vector<vector<char>> grid(3, vector<char>(3, '_'));
    int moves = 5;
    int count = 0;
    bool flag = false;

    vector<pair<bool, char>> arr(9, {false, '_'});

    int position;
    while (moves--)
    {
        cout << "Enter the position to put X (0-8): ";
        cin >> position;
        if (position < 0 || position >= 9 || arr[position].first)
        {
            cout << "Invalid position! Try again.\n";
            moves++;
            continue;
        }

        arr[position].first = true;
        arr[position].second = 'U';

        if (count == 0)
        {
            FirstMove(arr);
            count++;
        }
        else
        {
            SubsequentMoves(arr);
        }

        display(arr, grid);

        int winner = IsWinner(arr);
        if (winner == 1)
        {
            cout << "Computer Wins" << endl;
            flag = true;
            break;
        }
        else if (winner == 2)
        {
            cout << "User Wins" << endl;
            flag = true;
            break;
        }
    }

    if (!flag)
    {
        cout << "It's a Tie" << endl;
    }

    return 0;
}
