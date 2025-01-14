// Write a method void printArray(int[][]arr)
// Prints array elements clockwise and anti-clockwise alternatively.
// Input :
// 1 2 3
// 4 5 6
// 7 8 9
// Output :
// 1 2 3 6 9 8 7 4 5
// 3 2 1 4 7 8 9 6 5

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<int> clockwise;

    vector<int> anti_clockwise;

    int right_bound = m - 1;
    int left_bound = 0;
    int top_bound = 0;
    int bottom_bound = n - 1;

    int total = n * m;
    while (total--)
    {
        for (int i = left_bound; i <= right_bound && total; i++)
        {
            clockwise.push_back(grid[top_bound][i]);
        }
        top_bound++;
        for (int j = top_bound; j <= bottom_bound && total; j++)
        {
            clockwise.push_back(grid[j][right_bound]);
        }
        right_bound--;
        for (int i = right_bound; i >= left_bound && total; i--)
        {
            clockwise.push_back(grid[bottom_bound][i]);
        }
        bottom_bound--;
        for (int j = bottom_bound; j >= top_bound && total; j--)
        {
            clockwise.push_back(grid[j][left_bound]);
        }
        left_bound++;
    }

    total = n * m;
    right_bound = m - 1;
    left_bound = 0;
    top_bound = 0;
    bottom_bound = n - 1;

    while (total--)
    {

        for (int i = right_bound; i >= left_bound && total; i--)
        {
            anti_clockwise.push_back(grid[top_bound][i]);
        }
        top_bound++;

        for (int j = top_bound; j <= bottom_bound && total; j++)
        {
            anti_clockwise.push_back(grid[j][left_bound]);
        }
        left_bound++;

        for (int i = left_bound; i <= right_bound && total; i++)
        {
            anti_clockwise.push_back(grid[bottom_bound][i]);
        }
        bottom_bound--;

        for (int j = bottom_bound; j >= top_bound && total; j--)
        {
            anti_clockwise.push_back(grid[j][right_bound]);
        }
        right_bound--;
    }

    for (int i = 0; i < clockwise.size(); i++)
    {
        cout << clockwise[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < anti_clockwise.size(); i++)
    {
        cout << anti_clockwise[i] << " ";
    }
}

int main()
{
    int n, m;
    // cout>>"Enter the number of rows: ";
    cin >> n;
    // cout<<"Enter the number of columns: ";
    cin >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    printArray(grid);

    return 0;
}