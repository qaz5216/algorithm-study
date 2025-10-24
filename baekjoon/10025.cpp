#include <iostream>

using namespace std;

int arr[1000001];
int dp[1000001];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b] = a;
    }
    dp[0] = arr[0];
    int mx = dp[0];
    for (int i = 1; i < 1000001; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
        if (i - 2 * k - 1 >= 0)
        {
            dp[i] -= arr[i - 2 * k - 1];
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}