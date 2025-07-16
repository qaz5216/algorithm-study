#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> edge[100001];
int dp[100001][20];
int depth[100001];
vector<int> ans;
vector<pair<int, int>> Q;
void dfs(int cur, int prev)
{
    for (int next : edge[cur])
    {
        if (next == prev)
            continue;
        dp[next][0] = cur;
        depth[next] = depth[cur] + 1;
        dfs(next, cur);
    }
}

int LCA(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);
    int gap = depth[a] - depth[b];
    for (int i = 0; i < 20; i++)
    {
        if (gap % 2 == 1)
            a = dp[a][i];
        gap = gap / 2;
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 19; i >= 0; i--)
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
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    { // 질문입력
        int a, b;
        cin >> a >> b;
        Q.push_back({a, b});
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[j][i] = dp[dp[j][i - 1]][i - 1];
            // dp[1][1] 1의 2번째 조상은 dp[dp[1][0]][0];
        }
    }
    int idx = M - 1;
    while (M--)
    {
        int a, b;
        a = Q[idx - M].first;
        b = Q[idx - M].second;
        ans.push_back(LCA(a, b));
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}