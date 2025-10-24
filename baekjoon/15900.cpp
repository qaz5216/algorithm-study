#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> edge[500001];
bool visit[500001] = {false};
int ans = 0;
void dfs(int cur, int dist)
{
    int cnt = 0;
    for (int next : edge[cur])
    {
        if (!visit[next])
        {
            visit[next] = true;
            cnt++;
            dfs(next, dist + 1);
        }
    }
    if (cnt == 0)
    {
        ans += dist;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    visit[1] = true;
    dfs(1, 0);
    if (ans % 2 == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}