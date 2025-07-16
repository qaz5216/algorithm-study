#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
    int n, m, t;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int start = 0, end = 1, mid;
    int find, min = arr[n - 1] - arr[0];
    while (start < n && end < n)
    {
        find = arr[end] - arr[start];
        if (find >= m)
        {
            if (min >= find)
                min = find;
            start++;
        }
        else
        {
            end++;
        }
    }
    cout << min;

    return 0;
}