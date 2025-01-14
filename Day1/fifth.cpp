// Write a program to find the smallest number divisible by all the numbers between 1 to n.

#include <bits/stdc++.h>
using namespace std;

int check(int n)
{
    int LCM = 1;
    for (int i = 2; i <= n; i++)
    {
        LCM = lcm(i, LCM);
    }
    return LCM;
}

int main()
{
    int n;
    cin >> n;
    cout << "smallest number divisible by all the numbers between 1 to n is " << check(n) << endl;

    return 0;
}