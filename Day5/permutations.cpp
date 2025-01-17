// Find all interleavings of given strings that can be formed from all the characters of the first and
// second string where the order of characters is preserved.

#include <bits/stdc++.h>
using namespace std;

void permutation(string s1, string s2, int i, int j, string temp, vector<string> &ans)
{
    if (i == s1.size() && j == s2.size()) // base case
    {
        ans.push_back(temp);
        return;
    }

    if (i == s1.size()) // when 1st string ends
    {
        permutation(s1, s2, i, j + 1, temp + s2[j], ans);
    }
    else if (j == s2.size()) // when second string ends
    {
        permutation(s1, s2, i + 1, j, temp + s1[i], ans);
    }
    else // processing
    {
        permutation(s1, s2, i, j + 1, temp + s2[j], ans);
        permutation(s1, s2, i + 1, j, temp + s1[i], ans);
    }
}

int main()
{
    string s1 = "";
    string s2 = "";
    cin >> s1;
    cin >> s2;

    int i = 0;
    int j = 0;

    string temp = "";
    vector<string> ans;
    permutation(s1, s2, i, j, temp, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}