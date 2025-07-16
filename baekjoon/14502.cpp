#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int board[64];
int tmp[8][8];
int ans = 0;
bool visit[8][8];

void dfs(int x, int y)
{
    tmp[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (!visit[nx][ny] && tmp[nx][ny] != 1)
            {
                visit[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}

void spread()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j] || tmp[i][j] != 2)
                continue;
            dfs(i, j);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tmp[i][j] == 0)
                cnt++;
        }
    }
    ans = max(ans, cnt);
}
bool flag = false;
void wall(int idx, int cnt)
{
    if (cnt == 3)
    {
        flag = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp[i][j] = board[i * 8 + j];
            }
        }
        spread();
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i * 8 + j <= idx)
                continue;
            if (board[i * 8 + j] == 0)
            {
                board[i * 8 + j] = 1;
                wall(i * 8 + j, cnt + 1);
                board[i * 8 + j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i * 8 + j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i * 8 + j] == 0)
            {
                board[i * 8 + j] = 1;
                wall(i * 8 + j, 1);
                board[i * 8 + j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}