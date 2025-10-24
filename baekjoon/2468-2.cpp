#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n;
int board[102][102];
bool visit[102][102];
int ans;
int mh;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> q;

void bfs(int rain)
{ // rain까진 물에 잠긴다
    int cnt = 0;
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (board[i][j] <= rain || visit[i][j])
                continue;
            cnt++;
            q.push({i, j});
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (!visit[nx][ny] && board[nx][ny] > rain)
                    {
                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    ans = max(ans, cnt);
}

int main()
{
    cin >> n;
    mh = 0;
    ans = 1; // 물높이가 1미만일때
    int height;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> height;
            board[i][j] = height;
            mh = max(mh, height);
        }
    }
    for (int i = 1; i < mh; i++)
    {
        bfs(i);
    }
    cout << ans;
    return 0;
}