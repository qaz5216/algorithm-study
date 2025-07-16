#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> edge[201];
int V[201];
bool isfill[201];

bool dfs(int x)
{
    for (int e : edge[x])
    {
        if (isfill[e])
            continue;
        isfill[e] = true;
        if (V[e] == 0 || dfs(V[e]))
        {
            V[e] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int a, x;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> x;
            edge[i].push_back(x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        memset(isfill, false, sizeof(isfill));
        if (dfs(i))
            ans++;
    }
    cout << ans;
    return 0;
}