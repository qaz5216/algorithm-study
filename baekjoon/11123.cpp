#include <iostream>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int cnt;
int h, w;
char board[101][101];
bool visit[101][101];

void dfs(int x, int y)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w)
        {
            if (board[nx][ny] == '#' && !visit[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> h >> w;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> board[i][j];
            }
        }
        cnt = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (board[i][j] == '#')
                {
                    if (!visit[i][j])
                    {
                        cnt++;
                        dfs(i, j);
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}