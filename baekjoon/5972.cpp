#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> v[50001];
bool visit[50001];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        visit[cur] = true;
        if (cur == n)
        {
            cout << cost;
            break;
        }
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (!visit[v[cur][i].first])
                pq.push({cost + v[cur][i].second, v[cur][i].first});
        }
    }
    while (!pq.empty())
    {
        pq.pop();
    }
    return 0;
}