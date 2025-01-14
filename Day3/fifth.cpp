// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in place, which means you have to modify the input 2D matrix directly.
// DO NOT allocate another 2D matrix and do the rotation.

#include <bits/stdc++.h>
using namespace std;

void rotation(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    rotation(matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}