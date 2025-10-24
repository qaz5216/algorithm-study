#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> edge;
int p[100001];

int find(int x)
{
    if (x == p[x])
        return x;
    else
        return find(p[x]);
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (a > b)
        p[a] = b;
    else
        p[b] = a;
    return;
}

bool isunion(int a, int b)
{
    return find(a) == find(b);
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({c, {a, b}});
    }
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
    }
    int cost = 0;
    int maxcost = 0;
    for (int i = 0; i < M; i++)
    {

        if (!isunion(edge[i].second.first, edge[i].second.second))
        {
            myunion(edge[i].second.first, edge[i].second.second);
            maxcost = max(maxcost, edge[i].first);
            cost += edge[i].first;
        }
    }
    cout << cost - maxcost;
    return 0;
}

// 최소비용으로 union 하고 가장 높은 비용 길을 끊자
