#include <iostream>
#include <queue>

using namespace std;

int dp[100001];
int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < 100001; i++)
    {
        dp[i] = -1;
    }
    queue<int> q;
    q.push(x);
    dp[x] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur * 2 <= 100000)
        {
            if (dp[cur * 2] == -1)
            {
                dp[cur * 2] = dp[cur] + 1;
                q.push(cur * 2);
            }
        }
        if (cur + 1 <= 100000)
        {
            if (dp[cur + 1] == -1)
            {
                dp[cur + 1] = dp[cur] + 1;
                q.push(cur + 1);
            }
        }
        if (cur - 1 >= 0)
        {
            if (dp[cur - 1] == -1)
            {
                dp[cur - 1] = dp[cur] + 1;
                q.push(cur - 1);
            }
        }
    }
    cout << dp[y];
    return 0;
}