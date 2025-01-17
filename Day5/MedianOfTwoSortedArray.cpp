// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

#include <bits/stdc++.h>
using namespace std;

void Median(vector<int> v1, vector<int> v2)
{
    int length1 = v1.size();
    int length2 = v2.size();
    double median;

    int pointer1 = 0;
    int pointer2 = 0;

    int mid = (length1 + length2) / 2;

    int curr = 0;
    int prev = 0;

    for (int i = 0; i <= mid; i++)
    {
        prev = curr;
        if (pointer1 < length1 && (pointer2 >= length2 || v1[pointer1] <= v2[pointer2]))
        {
            curr = v1[pointer1++];
        }
        else
        {
            curr = v2[pointer2++];
        }
    }

    if ((length1 + length2) % 2 == 0)
    {
        median = (curr + prev) / 2.0;
    }
    else
    {
        median = curr;
    }
    cout << median << endl;
}

int main()
{
    int length1, length2;

    cout << "Input the size of array1: ";
    cin >> length1;
    vector<int> v1(length1);

    cout << "Input array1: ";
    for (int i = 0; i < length1; i++)
    {
        cin >> v1[i];
    }

    cout << "Input the size of array2: ";
    cin >> length2;
    vector<int> v2(length2);

    cout << "Input array2: ";
    for (int i = 0; i < length2; i++)
    {
        cin >> v2[i];
    }

    // Ensure the arrays are sorted
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    Median(v1, v2);

    return 0;
}