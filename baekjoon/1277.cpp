#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, w;
double m;
pair<int, int> board[1001];
vector<pair<double, int>> arr[1001];
double dp[1001];
bool visit[1001];
const double INF = 1e18;

int main()
{
    cin >> n >> w;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        board[i] = {a, b};
        for (int j = 0; j < i; j++)
        {
            double x = board[i].first - board[j].first;
            double y = board[i].second - board[j].second;
            double dist = sqrt(x * x + y * y);
            if (dist <= m)
            {
                arr[i].push_back({dist, j});
                arr[j].push_back({dist, i});
            }
        }
        dp[i] = INF;
    }
    //+2*10^10;
    for (int i = 0; i < w; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[b].push_back({0, a});
        arr[a].push_back({0, b});
    }
    double ans = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push({0, 1});
    dp[0] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        double cost = pq.top().first;
        pq.pop();
        if (visit[cur])
            continue;
        visit[cur] = true;
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i].second;
            double nextcost = arr[cur][i].first + cost;
            if (dp[next] > nextcost)
            {
                dp[next] = nextcost;
                pq.push({nextcost, next});
            }
        }
    }
    cout << (int)floor(dp[n] * 1000);
    return 0;
}