#include <iostream>

using namespace std;

#define ll long long

int N, M;
ll dp[1001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    ll psum = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        psum += a;
        dp[psum % M]++;
    }
    ll ans = 0;
    for (int i = 0; i < M; i++)
    {
        ans += ((dp[i] * (dp[i] - 1)) / 2);
    }
    cout << ans + dp[0];
    return 0;
}