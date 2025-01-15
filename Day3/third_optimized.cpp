// Write an efficient algorithm that searches for a value in a m x n matrix.
// This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

bool search(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n - 1;
    int row = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (matrix[mid][0] == target)
            return true;

        if (matrix[mid][0] < target)
        {
            row = mid;
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    if (row == -1)
    {
        return false;
    }

    return binarySearch(matrix[row], 0, m - 1, target);
}

int main()
{
    int n, m, target;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    cin >> target;

    if (search(grid, target))
    {
        cout << "This value is present" << endl;
    }
    else
    {
        cout << "This value is not present" << endl;
    }

    return 0;
}
