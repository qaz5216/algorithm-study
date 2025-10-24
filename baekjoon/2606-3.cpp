#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int ans;
bool visit[101];
vector<int> edge[101];
queue<int> q;

int main()
{
    cin >> n >> m;
    int s, e;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        edge[s].push_back(e);
        edge[e].push_back(s);
    }
    ans = 0;
    visit[1] = true;
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int next : edge[cur])
        {
            if (visit[next])
                continue;
            visit[next] = true;
            ans++;
            q.push(next);
        }
    }
    cout << ans;
    return 0;
}