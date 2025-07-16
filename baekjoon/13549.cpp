#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dp[100001];

int main()
{
    int x, y;
    cin >> x >> y;
    memset(dp, -1, sizeof(dp));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dp[x] = 0;
    pq.push({0, x});
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int next = cur.second * 2;
        while (next < 100001 && next != 0)
        {
            if (dp[next] == -1)
            {
                dp[next] = cur.first;
                pq.push({cur.first, next});
            }
            next *= 2;
        }
        next = cur.second + 1;
        if (next < 100001)
        {
            if (dp[next] == -1)
            {
                dp[next] = cur.first + 1;
                pq.push({cur.first + 1, next});
            }
        }
        next = cur.second - 1;
        if (next >= 0)
        {
            if (dp[next] == -1)
            {
                dp[next] = cur.first + 1;
                pq.push({cur.first + 1, next});
            }
        }
    }
    cout << dp[y];
    return 0;
}