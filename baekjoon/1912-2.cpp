#include <iostream>

using namespace std;

int n;
int arr[100001];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
    }
    int mx = -1000;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
    return 0;
}