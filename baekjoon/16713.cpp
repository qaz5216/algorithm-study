#include <iostream>
#include <vector>
int N, Q;

using namespace std;
int dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int tmp;
        cin >> tmp;
        if (i == 1)
            dp[i] = tmp;
        else
            dp[i] = dp[i - 1] ^ tmp;
    }
    int ans = 0;
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
        {
            ans ^= dp[b];
        }
        else
            ans ^= (dp[b] ^ dp[a - 1]);
    }
    cout << ans;
    return 0;
}