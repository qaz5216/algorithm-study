#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e9;

int arr[20001];
vector<pair<int, int>> edge[20001];
int main()
{
    int n, m, s;
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edge[x].push_back({y, z});
    }
    for (int i = 1; i <= n; i++)
        arr[i] = INF;
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    arr[s] = 0;
    while (!q.empty())
    {
        pair<int, int> now = q.top();
        q.pop();
        for (pair<int, int> next : edge[now.second])
        {
            if (arr[next.first] > now.first + next.second)
            {
                arr[next.first] = now.first + next.second;
                q.push({arr[next.first], next.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        (arr[i] == INF) ? cout << "INF\n" : cout << arr[i] << "\n";
    }

    return 0;
}