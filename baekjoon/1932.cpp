#include <iostream>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            // j==1
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + arr[i][j];
            // 1<j<i
            if (1 < j && j < i)
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
            // j==i
            if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
        }
    }
    int res = dp[n][1];
    for (int i = 2; i <= n; i++)
    {
        res = max(res, dp[n][i]);
    }
    cout << res;
    return 0;
}