#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> edge[100001];
vector<pair<int, int>> Q;
vector<pair<int, int>> ans;

int dp[100001][18];
int depth[100001];
int mx[100001][18];
int mn[100001][18];

void dfs(int cur, int prev, int dep, int dist)
{
    dp[cur][0] = prev;
    depth[cur] = dep;
    mx[cur][0] = dist;
    mn[cur][0] = dist;
    for (pair<int, int> e : edge[cur])
    {
        if (e.first == prev)
            continue;
        dfs(e.first, cur, dep + 1, e.second);
    }
}

pair<int, int> LCA(int a, int b)
{
    int minres = 1000001, maxres = -1;
    if (depth[a] < depth[b])
        swap(a, b);
    int gap = depth[a] - depth[b];
    for (int i = 0; i < 18; i++)
    {
        if (gap % 2 == 1)
        {
            maxres = max(maxres, mx[a][i]);
            minres = min(minres, mn[a][i]);
            a = dp[a][i];
        }
        gap /= 2;
    }
    if (a == b)
    {
        return {minres, maxres};
    }
    for (int i = 17; i >= 0; i--)
    {
        if (dp[a][i] != dp[b][i])
        {

            maxres = max(maxres, mx[a][i]);
            minres = min(minres, mn[a][i]);
            maxres = max(maxres, mx[b][i]);
            minres = min(minres, mn[b][i]);
            a = dp[a][i];
            b = dp[b][i];
        }
    }

    maxres = max(maxres, mx[a][0]);
    minres = min(minres, mn[a][0]);
    maxres = max(maxres, mx[b][0]);
    minres = min(minres, mn[b][0]);
    return {minres, maxres};
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
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        Q.push_back({a, b});
    }
    dfs(1, 0, 0, 0);
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= N; j++)
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= N; j++)
        {
            mx[j][i] = max(mx[dp[j][i - 1]][i - 1], mx[j][i - 1]);
            mn[j][i] = min(mn[dp[j][i - 1]][i - 1], mn[j][i - 1]);
        }
    for (int i = 0; i < K; i++)
    {
        int a, b;
        a = Q[i].first;
        b = Q[i].second;
        pair<int, int> tmp = LCA(a, b);
        ans.push_back(tmp);
    }
    for (pair<int, int> answer : ans)
    {
        cout << answer.first << " " << answer.second << "\n";
    }
    return 0;
}