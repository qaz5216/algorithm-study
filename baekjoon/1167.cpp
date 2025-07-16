#include <iostream>
#include <vector>
using namespace std;

int N;

vector<pair<int, int>> edges[100001];
bool visit[100001] = {false};
int maxval = -9999;
int maxi = -1;
void dfs(int x, int val)
{
    visit[x] = true;
    if (maxval < val)
    {
        maxval = val;
        maxi = x;
    }
    for (pair<int, int> e : edges[x])
    {
        if (!visit[e.first])
        {
            dfs(e.first, val + e.second);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 1; i < N + 1; i++)
    {
        bool exit = true;
        int a;
        cin >> a;
        while (exit)
        {
            int b, c;
            cin >> b;
            if (b == -1)
            {
                exit = false;
                continue;
            }
            cin >> c;
            edges[a].push_back({b, c});
        }
    }
    dfs(1, 0);
    for (int i = 1; i < N + 1; i++)
    {
        visit[i] = false;
    }
    dfs(maxi, 0);
    cout << maxval;
    return 0;
}