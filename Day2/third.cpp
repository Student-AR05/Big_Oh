// Write a program to print the below pattern:
// \*****/
// *\***/*
// **\*/**
// ***/***
// **/*\**
// */***\*
// /*****\

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> Pattern(int n)
{
    vector<vector<char>> ans(n, vector<char>(n, '*'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                ans[i][j] = '/';
            }
            else if (i == j && i + j != n - 1)
            {
                ans[i][j] = '\\';
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of pattern" << endl;
    cin >> n;

    vector<vector<char>> result = Pattern(n);

    cout << "The pattern is" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}