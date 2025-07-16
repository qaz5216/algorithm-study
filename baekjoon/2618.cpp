#include <iostream>
#include <vector>

using namespace std;

int n, w;
pair<int, int> arr[1001];
int dp[1001][1001];

int calc(pair<int, int> s, pair<int, int> e)
{
    int dist = 0;
    dist += abs(e.first - s.first);
    dist += abs(e.second - s.second);
    return dist;
}

int police(int x, int y)
{
    if (x == w || y == w)
    {
        return 0;
    }
    if (dp[x][y] != -1)
    {
        return dp[x][y];
    }
    int next = max(x, y) + 1;
    int dist1, dist2;
    if (x == 0)
        dist1 = calc({1, 1}, arr[next]);
    else
        dist1 = calc(arr[x], arr[next]);
    if (y == 0)
        dist2 = calc({n, n}, arr[next]);
    else
        dist2 = calc(arr[y], arr[next]);
    int r1 = dist1 + police(next, y);
    int r2 = dist2 + police(x, next);
    dp[x][y] = min(r1, r2);
    return dp[x][y];
}

int main()
{
    cin >> n;
    cin >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < w; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << police(0, 0) << "\n";
    int x = 0, y = 0;
    while (x != w && y != w)
    {
        int next = max(x, y) + 1;
        int dist1, dist2;
        if (x == 0)
            dist1 = calc({1, 1}, arr[next]);
        else
            dist1 = calc(arr[x], arr[next]);
        if (y == 0)
            dist2 = calc({n, n}, arr[next]);
        else
            dist2 = calc(arr[y], arr[next]);
        if (dp[next][y] + dist1 < dp[x][next] + dist2)
        {
            cout << 1 << "\n";
            x = next;
        }
        else
        {
            cout << 2 << "\n";
            y = next;
        }
    }
    return 0;
}