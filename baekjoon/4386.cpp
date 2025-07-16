#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<pair<double, double>> star;
vector<pair<double, pair<int, int>>> edge;
int p[101];
double dist(double x1, double x2, double y1, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(pow(dx, 2) + pow(dy, 2));
}

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

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double x, y;
        cin >> x >> y;
        star.push_back({x, y});
        p[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            edge.push_back({dist(star[i].first, star[j].first, star[i].second, star[j].second), {i, j}});
        }
    }
    sort(edge.begin(), edge.end());
    double ans = 0;
    for (pair<double, pair<int, int>> e : edge)
    {
        if (find(e.second.first) != find(e.second.second))
        {
            myunion(e.second.first, e.second.second);
            ans += e.first;
        }
    }
    cout << fixed;
    cout.precision(2);

    cout << ans;

    return 0;
}