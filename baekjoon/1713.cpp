#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
pair<pair<int, int>, int> arr[21];
int dp[21];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.first == b.first.first)
        return a.first.second < b.first.second;
    return a.first.first < b.first.first;
}

bool cmp2(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.second < b.second;
}

int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        int x = 0;
        bool find = false;
        for (int j = 0; j < N; j++)
        {
            if (arr[j].second == a)
            {
                arr[j].first.first++;
                find = true;
            }
        }
        if (find)
            continue;
        sort(arr, arr + N, cmp);
        arr[0].first.first = 1;
        arr[0].first.second = i;
        arr[0].second = a;
        dp[0] = a;
    }
    sort(arr, arr + N, cmp2);
    for (int i = 0; i < N; i++)
    {
        if (arr[i].first.first != 0)
            cout << arr[i].second << " ";
    }
    return 0;
}
