#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, M;
vector<int> g[100001];
vector<int> st;
bool visit[100001];

void dfs(int n)
{
    for (int next : g[n])
    {
        if (visit[next])
            continue;
        visit[next] = true;
        dfs(next);
    }
    st.push_back(n);
}

void dfs2(int n)
{
    for (int next : g[n])
    {
        if (visit[next])
            continue;
        visit[next] = true;
        dfs2(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < M; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        memset(visit, false, sizeof(visit));
        st.clear();
        for (int i = 1; i <= N; i++)
        {
            if (visit[i])
                continue;
            visit[i] = true;
            dfs(i);
        }
        memset(visit, false, sizeof(visit));
        reverse(st.begin(), st.end());
        int ans = 0;
        for (int n : st)
        {
            if (visit[n])
                continue;
            visit[n] = true;
            dfs2(n);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}