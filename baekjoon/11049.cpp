#include <iostream>
#include <vector>

using namespace std;

int n;
pair<int, int> arr[501];

int dp[501][501];
pair<int, int> dparr[501][501];

int calc(int x, int mid, int y)
{
    return dparr[x][mid].first * dparr[x][mid].second * dparr[mid + 1][y].second;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        dparr[i][i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int x = 1; x + i <= n; x++)
        {
            int y = x + i;
            dp[x][y] = 1e9;
            for (int mid = x; mid < y; mid++)
            {
                dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + calc(x, mid, y));
            }
            dparr[x][y].first = arr[x].first;
            dparr[x][y].second = arr[y].second;
        }
    }
    cout << dp[1][n];
    return 0;
}

/*
dp[1][3]=dp[1][1]+dp[2][3]+

*/