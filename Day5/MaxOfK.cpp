// You are given an array of integers nums, there is a sliding window of size k
// which is moving from the very left of the array to the very right.
// You can only see the k numbers in the window.
// Each time the sliding window moves right by one position.

#include <bits/stdc++.h>
using namespace std;

// function to find maximum of k size window
void MaxOfK(vector<int> v, int k)
{
    priority_queue<pair<int, int>> pq; // max heap initialization
    for (int i = 0; i < k; i++)        // inserting k values
    {
        pq.push({v[i], i});
    }
    cout << pq.top().first << ' '; // printing maximum element of first k sized window

    for (int i = k; i < v.size(); i++) // inserting remaining values
    {
        pq.push({v[i], i});

        while (pq.top().second <= i - k) // removing the max element if it is not in the current window
        {
            pq.pop();
        }

        cout << pq.top().first << ' ';
    }
    cout << endl;
}

int main()
{
    int length;

    cout << "Input the size of array ";
    cin >> length;
    vector<int> v(length);

    for (int i = 0; i < length; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;

    MaxOfK(v, k);
}