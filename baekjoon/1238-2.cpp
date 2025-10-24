#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, X;
vector<pair<int, int>> g[1001];
vector<pair<int, int>> rg[1001];
int dist[1001];
int arr[1001];
int main()
{
    cin >> N >> M >> X;
    for (int i = 0; i < M; i++)
    {
        int s, e, t;
        cin >> s >> e >> t;
        g[s].push_back({t, e});
        rg[e].push_back({t, s});
    }
    for (int i = 1; i <= N; i++)
    {
        arr[i] = 0;
    }
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 1e9;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, X});
    dist[X] = 0;
    while (!pq.empty())
    {
        pair<int, int> now = pq.top();
        pq.pop();
        for (pair<int, int> next : g[now.second])
        {
            if (dist[next.second] > now.first + next.first)
            {
                dist[next.second] = now.first + next.first;
                pq.push({now.first + next.first, next.second});
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        arr[i] += dist[i]; // X->집까지 거리
        cout << dist[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        dist[i] = 1e9;
    }
    pq.push({0, X});
    dist[X] = 0;
    while (!pq.empty())
    {
        pair<int, int> now = pq.top();
        pq.pop();
        for (pair<int, int> next : rg[now.second])
        {
            if (dist[next.second] > now.first + next.first)
            {
                dist[next.second] = now.first + next.first;
                pq.push({now.first + next.first, next.second});
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        arr[i] += dist[i]; // 집->X 까지거리
        cout << dist[i] << " ";
    }
    cout << "\n";
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}