#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> arr;

int record[100];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n, a, b, result = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end(), cmp);
    record[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        record[i] = 1;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[i].second < arr[j].second)
            {
                record[i] = max(record[j] + 1, record[i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        result = max(result, record[i]);
    }
    cout << n - result;

    return 0;
}
