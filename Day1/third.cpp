// Find the largest number less than N whose each digit is prime number

#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
    bool flag = true;
    int temp = n;
    while (temp)
    {
        int a = temp % 10;
        if (a == 2 || a == 3 || a == 5 || a == 7)
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
        temp = temp / 10;
    }
    return flag;
}

int main()
{
    int n;
    cin >> n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (check(i))
        {
            cout << "largest number less than N whose each digit is prime number is " << i << endl;
            break;
        }
    }

    return 0;
}
