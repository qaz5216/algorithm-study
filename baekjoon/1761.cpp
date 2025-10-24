#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define ll long long

int N, M;
vector<pair<int, ll>> edge[40001];
ll dist[40001];
ll depth[40001];
ll dp[40001][17];
vector<ll> ans;
void dfs(int cur, int prev, ll val, int dep)
{
    dist[cur] = val;
    dp[cur][0] = prev;
    depth[cur] = dep;
    for (pair<int, int> e : edge[cur])
    {
        if (e.first == prev)
            continue;
        dfs(e.first, cur, val + e.second, dep + 1);
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int gap = depth[a] - depth[b];
    for (int i = 0; i < 17; i++)
    {
        if (gap % 2 == 1)
        {
            a = dp[a][i];
        }
        gap /= 2;
    }
    if (a == b)
        return a;
    for (int i = 16; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i])
        {
            a = dp[a][i];
            b = dp[b][i];
        }
    }
    return dp[a][0];
}

int main()
{
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cin >> M;
    dfs(1, 0, 0, 0);
    for (int i = 1; i < 17; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
        }
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int tmp = LCA(a, b);
        ans.push_back(dist[a] + dist[b] - 2 * dist[tmp]);
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}