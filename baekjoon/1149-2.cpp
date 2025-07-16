#include <iostream>

using namespace std;

int N;

int cost[1001][3];
int dp[1001][3];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
        if (i == 0)
        {
            dp[i][0] = cost[i][0];
            dp[i][1] = cost[i][1];
            dp[i][2] = cost[i][2];
        }
    }
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(cost[i][0] + dp[i - 1][1], cost[i][0] + dp[i - 1][2]);
        dp[i][1] = min(cost[i][1] + dp[i - 1][0], cost[i][1] + dp[i - 1][2]);
        dp[i][2] = min(cost[i][2] + dp[i - 1][0], cost[i][2] + dp[i - 1][1]);
    }
    int mn = min(dp[N - 1][0], dp[N - 1][1]);
    mn = min(mn, dp[N - 1][2]);
    cout << mn;
    return 0;
}

/*
30 40 50
1  30 30

*/
