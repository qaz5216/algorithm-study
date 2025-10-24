#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
int shark[51][3];
vector<int> edge[51];
bool check[51];
int Eat[51];
int ans = 0;

bool dfs(int x)
{
    for (int next : edge[x])
    {
        if (check[next])
            continue;
        check[next] = true;
        if (Eat[next] == 0 || dfs(Eat[next]))
        {
            Eat[next] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> shark[i][0] >> shark[i][1] >> shark[i][2];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1] && shark[i][2] == shark[j][2])
            {
                edge[i].push_back(j);
            }
            else if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2])
            {
                edge[i].push_back(j);
            }
            else if (shark[i][0] <= shark[j][0] && shark[i][1] <= shark[j][1] && shark[i][2] <= shark[j][2])
            {
                edge[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            memset(check, false, sizeof(check));
            if (dfs(i))
            {
                ans++;
            }
        }
    }
    cout << N - ans;
    return 0;
}