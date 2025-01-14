// Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. The function should find all triplets in the array that sum up to the target sum and return a two-dimensional array of all these triplets. The numbers in each triplet should be ordered in ascending order, and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. If no three numbers sum up to the target sum, the function should return an empty array.
// Ex:
// target_sum = 6
// nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
// result = [[1, 2, 3]]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> arr, int target)
{
    vector<vector<int>> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> v;
        int new_target = target - arr[i];
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            if (arr[left] + arr[right] == new_target)
            {
                v.push_back(arr[i]);
                v.push_back(arr[left]);
                v.push_back(arr[right]);

                ans.push_back(v);
                v.clear();
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < new_target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return ans;
}

int main()
{

    int n;
    int target;
    cout << "Input size of array ";
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    cout << "Target ";
    cin >> target;

    vector<vector<int>> result = ThreeSum(values, target);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}