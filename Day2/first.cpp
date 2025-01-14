// Write a program to remove duplicate values from an array and returns an array of unique values. int[] removeDuplicates(int[]values)
// Ex:
// values = [2, 4, 6, 2, 8, 10, 4, 12, 14, 6]
// result = [2, 4, 6, 8, 10, 12, 14]

#include <bits/stdc++.h>
using namespace std;

vector<int> removeDuplicates(vector<int> &v)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }
    set<int>::iterator itr;
    vector<int> ans;
    for (itr = s.begin(); itr != s.end(); itr++)
    {
        ans.push_back(*itr);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Input size of array ";
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> result = removeDuplicates(v);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}