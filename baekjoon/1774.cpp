#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int p[1001];
pair<int, int> god[1001];
vector<pair<double, pair<int, int>>> edge;
double ans;
int find(int x)
{
    if (x == p[x])
        return x;

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
}

double dist(int a, int b)
{
    double x = god[a].first - god[b].first;
    double y = god[a].second - god[b].second;
    double distance = sqrt(pow(x, 2) + pow(y, 2));
    return distance;
}
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        myunion(a, b);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            edge.push_back({dist(i, j), {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    ans = 0;
    for (pair<double, pair<int, int>> e : edge)
    {
        // cout<<"what "<<e.second.first<<"??"<<e.second.second<<" = "<<e.first<<endl;
        if (find(e.second.first) != find(e.second.second))
        {
            myunion(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
};

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        cin >> x >> y;
        god[i] = {x, y};
    }
    solve();

    return 0;
}