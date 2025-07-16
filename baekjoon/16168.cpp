#include <iostream>
#include <vector>
using namespace std;

int V, E;
vector<int> e[3001];
int degree[3001];
bool visit[3001];

void dfs(int v)
{
    visit[v] = true;
    for (int next : e[v])
    {
        if (!visit[next])
        {
            dfs(next);
        }
    }
}

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    dfs(1);
    for (int i = 1; i <= V; i++)
    {
        if (!visit[i])
        {
            cout << "NO";
            return 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= V; i++)
    {
        if (degree[i] % 2 == 1)
        {
            cnt++;
        }
    }
    if (cnt == 0 || cnt == 2)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}