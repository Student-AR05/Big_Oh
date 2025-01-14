// Write a program (without using inbuilt functions and not using Strings or array)
// to swap first and last digits of any number

#include <bits/stdc++.h>
using namespace std;
int SwapDigit(int number)
{
    int temp1 = number;
    int lastDigit = temp1 % 10;
    int firstDigit = 0;
    int num2 = 0;
    while (temp1)
    {
        firstDigit = temp1 % 10;
        temp1 = temp1 / 10;
    }

    number = number / 10;
    number = number * 10 + firstDigit;
    int temp2 = number;

    while (temp2)
    {
        int a = temp2 % 10;
        num2 = num2 * 10 + a;
        temp2 = temp2 / 10;
    }
    num2 = num2 / 10;
    num2 = num2 * 10 + lastDigit;

    int num3 = 0;

    while (num2)
    {
        int a = num2 % 10;
        num3 = num3 * 10 + a;
        num2 = num2 / 10;
    }

    number = num3;
    return number;
}

int main()
{
    int number;
    cin >> number;
    cout << SwapDigit(number) << endl;

    return 0;
}