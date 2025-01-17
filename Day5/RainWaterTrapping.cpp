// Question 4:
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:

// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:
// Input: height = [1,1]
// Output: 1
// Constraints:
// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104
#include <bits/stdc++.h>
using namespace std;

int MaxStored(vector<int> v)
{
    int length = v.size();
    int i = 0;
    int j = length - 1;

    int maxStorage = 0;
    while (i < j)
    {
        maxStorage = max(min(v[i], v[j]) * (j - i), maxStorage);
        if (v[i] < v[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return maxStorage;
}

int main()
{
    int length = 0;
    cin >> length;

    vector<int> v(length);

    for (int i = 0; i < length; i++)
    {
        cin >> v[i];
    }

    int ans = MaxStored(v);

    cout << "Maximum rain water stored is: " << ans << endl;

    return 0;
}