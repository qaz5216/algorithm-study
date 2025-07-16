#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[21];
int m;
int dp[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (j - arr[i] >= 0)
                {
                    if (j == arr[i])
                        dp[j]++;
                    else
                    {
                        dp[j] += dp[j - arr[i]];
                    }
                }
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}