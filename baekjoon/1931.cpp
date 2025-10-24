#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arr;

int N;
int ans;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    sort(arr.begin(), arr.end(), cmp);
    ans++;
    int start = arr[0].second;
    for (int i = 1; i < N; i++)
    {
        if (start <= arr[i].first)
        {
            ans++;
            start = arr[i].second;
        }
    }
    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        pair<int, int> p = make_pair(s, e);
        arr.push_back(p);
    }
    ans = 0;
    solve();
    cout << ans;
    return 0;
}