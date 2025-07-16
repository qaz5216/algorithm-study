#include <iostream>

using namespace std;

int dp[6];
int maxnum[6];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 1; i < 6; i++)
        {
            if (i == a || i == b)
            {
                dp[i]++;
            }
            else
            {
                if (maxnum[i] < dp[i])
                {
                    maxnum[i] = dp[i];
                }
                dp[i] = 0;
            }
        }
    }
    for (int i = 1; i < 6; i++)
    {
        if (maxnum[i] < dp[i])
            maxnum[i] = dp[i];
    }
    int ans = 1;
    for (int i = 2; i < 6; i++)
    {
        if (maxnum[ans] < maxnum[i])
            ans = i;
    }
    cout << maxnum[ans] << " " << ans;
    return 0;
}