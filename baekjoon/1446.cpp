#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, d;
vector<pair<int, int>> road[10001];
bool visit[10001];
int dp[10001];

int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        road[b].push_back({a, c});
    }
    dp[0] = 0;
    for (int i = 1; i <= d; i++)
    {
        dp[i] = 1e9;
    }
    for (int i = 1; i <= d; i++)
    {
        if (road[i].size() == 0)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            for (int j = 0; j < road[i].size(); j++)
            {
                dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[road[i][j].first] + road[i][j].second));
            }
        }
    }
    cout << dp[d];
}