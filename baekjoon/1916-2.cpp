#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int s, e;
vector<pair<int, int>> bus[1001];
int dist[1001];
priority_queue<pair<int, int>> pq;

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        dist[i] = 1e9;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    cin >> s >> e;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int d = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if (dist[idx] < d)
            continue;
        for (int i = 0; i < bus[idx].size(); i++)
        {
            int nx = bus[idx][i].first;
            int nd = bus[idx][i].second;
            if (dist[nx] > d + nd)
            {
                pq.push({d + nd, nx});
                dist[nx] = d + nd;
            }
        }
    }
    cout << dist[e];
    return 0;
}