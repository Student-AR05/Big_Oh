// i) Write a method Boolean isValidSudoku(int[][]Sudoku)
// Returns true if the given Sudoku is correctly arranged otherwise false
// Write a method Boolean isValidSudoku(int[][]Sudoku)Returns true if the given Sudoku is correctly arranged otherwise false
// Determine if a 9 x 9 The Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Example :
// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false

#include <bits/stdc++.h>
using namespace std;

bool validation(vector<vector<int>> Suduko, int i, int j)
{
    bool arr[10] = {false};

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            int val = Suduko[i + row][j + col];
            if (val != 0)
            {
                if (arr[val])
                    return false;
                arr[val] = true;
            }
        }
    }
    return true;
}

bool validate(vector<int> matrix)
{
    bool arr[10] = {false};
    for (int i = 0; i < 9; i++)
    {
        if (matrix[i] != 0 && arr[matrix[i]] == true)
        {
            return false;
        }
        arr[matrix[i]] = true;
    }
    return true;
}

bool isValidSudoku(vector<vector<int>> Suduko)
{
    bool row, col, submatrix;
    for (int i = 0; i < 9; i++)
    {
        row = validate(Suduko[i]);
        if (row == false)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            swap(Suduko[i][j], Suduko[j][i]);
        }
    }

    for (int i = 0; i < 9; i++)
    {
        col = validate(Suduko[i]);
        if (col == false)
        {
            return false;
        }
    }

    for (int i = 0; i < 9; i += 3)
    {
        for (int j = 0; j < 9; j += 3)
        {
            submatrix = validation(Suduko, i, j);
            if (submatrix == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> sudoku = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {3, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (isValidSudoku(sudoku))
    {
        cout << "It is a valid arrangement" << endl;
    }
    else
    {
        cout << "It is not a valid arrangement" << endl;
    }

    return 0;
}