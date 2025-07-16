#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<pair<int, int>> stonex[100002]; // x,y좌표,아름다움 담자
vector<pair<int, int>> stoney[100002];

int main()
{
    cin >> n >> c;
    int mx = 0, my = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        stonex[a].push_back({b, c});
        stoney[b].push_back({a, c});
        mx = max(mx, a);
        my = max(my, b);
    }
    int xidx = mx;
    int yidx = 0;
    long long ans = 0;
    long long val = 0;
    int cnt = 0;
    while (true)
    {
        if (xidx < 0 || yidx > my + 1)
        {
            break;
        }
        if (cnt <= c)
        {
            for (int i = 0; i < stoney[yidx].size(); i++)
            {
                if (stoney[yidx][i].first <= xidx)
                {
                    cnt++;
                    val += (long long)stoney[yidx][i].second;
                }
            }
            yidx++;
        }
        else
        {
            for (int i = 0; i < stonex[xidx].size(); i++)
            {
                if (stonex[xidx][i].first <= yidx - 1)
                {
                    cnt--;
                    val -= (long long)stonex[xidx][i].second;
                }
            }
            xidx--;
        }
        if (cnt <= c)
        {
            ans = max(ans, val);
        }
    }
    cout << ans;
    return 0;
}
