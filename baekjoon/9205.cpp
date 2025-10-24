#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> ans;
int n;
pair<int, int> home;
vector<pair<int, int>> market;
pair<int, int> dest;
bool visit[101];

void input()
{
    int x, y;
    cin >> n;
    cin >> x >> y;
    home = {x, y};
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        market.push_back({x, y});
    }
    cin >> x >> y;
    dest = {x, y};
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }

    queue<pair<int, int>> q;
    q.push(home);
    bool can = false;
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (abs(dest.first - now.first) + abs(dest.second - now.second) <= 1000)
        {
            // cout<<"now("<<now.first<<","<<now.second<<") dest("<<dest.first<<","<<dest.second<<")"<<endl;
            can = true;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            pair<int, int> mart = market[i];
            if (abs(mart.first - now.first) + abs(mart.second - now.second) <= 1000 && !visit[i])
            {
                // cout<<"now("<<now.first<<","<<now.second<<") mart("<<mart.first<<","<<mart.second<<")"<<endl;
                q.push(mart);
                visit[i] = true;
            }
        }
    }
    if (can)
        ans.push_back("happy");
    else
        ans.push_back("sad");
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        input();
        solve();
        market.clear();
    }
    for (string answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}