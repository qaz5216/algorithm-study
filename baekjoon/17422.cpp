#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, Q;
long long arr[300001];
long long dp[300001];
long long maxdp[300001];
vector<long long> ans;
vector<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        maxdp[i] = dp[i] = arr[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        int a, b;
        cin >> a >> b;
        q.push_back({a, b});
    }
    for (int i = N / 2; i > 0; i--)
    {
        dp[i] = max(dp[i * 2], dp[i * 2 + 1]) + arr[i];
        maxdp[i] = max({arr[i] + dp[i * 2] + dp[i * 2 + 1], maxdp[i * 2], maxdp[i * 2 + 1]});
    }
    ans.push_back(maxdp[1]);
    for (int i = 0; i < Q; i++)
    {
        int idx = q[i].first;
        arr[idx] = dp[idx] = maxdp[idx] = q[i].second;
        if (idx > N / 2)
            idx /= 2;
        for (int j = idx; j > 0; j /= 2)
        {
            dp[j] = max(dp[j * 2], dp[j * 2 + 1]) + arr[j];
            maxdp[j] = max({arr[j] + dp[j * 2] + dp[j * 2 + 1], maxdp[j * 2], maxdp[j * 2 + 1]});
        }
        ans.push_back(maxdp[1]);
    }

    for (long long answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}