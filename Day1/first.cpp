// Write down a method boolean isNameValid(String  name).
// A name is valid if following conditions are satisfied:
// • It does not contain any vowel more than once.
// • If the name contains two ‘S’, then there is not any ‘T’ in between them (both in capital cases).

#include <bits/stdc++.h>
using namespace std;

bool isNameValid(string name)
{
    map<char, int> mp;
    for (int i = 0; i < name.size(); i++)
    {
        if (name[i] == 'a' || name[i] == 'A')
        {
            mp['a']++;
        }
        if (name[i] == 'e' || name[i] == 'E')
        {
            mp['e']++;
        }
        if (name[i] == 'i' || name[i] == 'I')
        {
            mp['i']++;
        }
        if (name[i] == 'o' || name[i] == 'O')
        {
            mp['o']++;
        }
        if (name[i] == 'u' || name[i] == 'U')
        {
            mp['u']++;
        }
        if (name[i] == 'S')
        {
            mp['S']++;
        }
        if (name[i] == 'T')
        {
            mp['T']++;
        }
    }

    bool flag = false;
    for (auto it : mp)
    {
        if (it.second >= 2 && (it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o' || it.first == 'u'))
        {
            return false;
        }
        else if (it.second >= 2 && it.first == 'S')
        {
            flag = true;
        }
    }
    if (flag)
    {
        int firstIndex = 0;
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] == 'S')
            {
                firstIndex = i;
                break;
            }
        }
        int lastIndex = 0;
        for (int i = name.size() - 1; i >= 0; i--)
        {
            if (name[i] == 'S')
            {
                lastIndex = i;
                break;
            }
        }
        for (int i = 0; i < name.size(); i++)
        {
            if (name[i] == 'T')
            {
                if (i > firstIndex && i < lastIndex)
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
    string name = "";
    cin >> name;
    cout << isNameValid(name) << endl;
    return 0;
}