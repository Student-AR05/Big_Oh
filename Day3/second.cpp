// Write a program to print all the possible combinations according to the input values.
// Example :
// Given Values
// '1' : ['Z', 'Y', 'A'],
// '2' : ['B', 'O'],
// '12' : ['L']
// '3' : ['U', 'P']
// Input: 123
// Output : [ZBU, ZBP, ZOU, ZOP, YBU, YBP, YOU, YOP, ABU, ABP, AOU, AOP, LU, LP]

#include <bits/stdc++.h>
using namespace std;

void combinations(vector<string> v, string temp, vector<string> &ans, int index, string input)
{
    if (index == input.size())
    {
        ans.push_back(temp);
        return;
    }

    if (input[index] == '1')
    {
        for (int i = 0; i < v[0].size(); i++)
        {
            combinations(v, temp + v[0][i], ans, index + 1, input);
        }
    }
    if (input[index] == '2')
    {
        for (int i = 0; i < v[1].size(); i++)
        {
            combinations(v, temp + v[1][i], ans, index + 1, input);
        }
    }
    if (input[index] == '3')
    {
        for (int i = 0; i < v[3].size(); i++)
        {
            combinations(v, temp + v[3][i], ans, index + 1, input);
        }
    }

    if (input[index] == '1' && input[index + 1] == '2')
    {
        for (int i = 0; i < v[2].size(); i++)
        {
            combinations(v, temp + v[2][i], ans, index + 2, input);
        }
    }
}

int main()
{
    vector<string> v;
    v.push_back("ZYA");
    v.push_back("BO");
    v.push_back("L");
    v.push_back("UP");

    vector<string> ans;
    string temp = "";

    string input;
    cin >> input;

    combinations(v, temp, ans, 0, input);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}