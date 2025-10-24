#include <iostream>

using namespace std;

/*
dp[i][j]=i~j까지 합칠때 최소값
*/
int dp[501][501] = {0};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int sum[501] = {0};
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            sum[i] += sum[i - 1] + a;
        }
        for (int i = 1; i < n; i++)
        {
            for (int x = 1; x <= n - i; x++)
            {
                int y = x + i;
                dp[x][y] = 1e9;
                for (int mid = x; mid < y; mid++)
                {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }
        cout << dp[1][n] << "\n";
    }
    return 0;
}

// 30 30 =60
// 40 50 =90
// 60 90 =150
