#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int dp[100001];
int ans[100001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (i == 0)
            dp[i] = arr[i];
        else
            dp[i] += dp[i - 1] + arr[i];
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            ans[i] = dp[b - 1];
        }
        else
        {
            ans[i] = dp[b - 1] - dp[a - 2];
        }
    }
    for (int i = 0; i < M; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}