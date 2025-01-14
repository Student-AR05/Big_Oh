// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
// return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
// You may assume all four edges of the grid are surrounded by water.
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &matrix, int r, int c)
{
    int n = matrix.size();
    int m = matrix[0].size();

    if (r < 0 || c < 0 || r >= n || c >= m || matrix[r][c] != '1')
    {
        return;
    }

    matrix[r][c] = '0';

    vector<int> n_row = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<int> n_col = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < 8; i++)
    {
        int new_row = r + n_row[i];
        int new_col = c + n_col[i];

        DFS(matrix, new_row, new_col);
    }
}

int countIsland(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                count++;

                DFS(matrix, i, j);
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m, '0'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << countIsland(matrix) << endl;

    return 0;
}
