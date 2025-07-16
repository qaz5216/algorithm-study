#include <iostream>
#include <cstring>
using namespace std;

int dx1[4] = {0, -1, 0, 1};
int dy1[4] = {1, 0, -1, 0};

int dx2[4] = {0, 1, 0, -1};
int dy2[4] = {1, 0, -1, 0};

int board[51][51];
int tmp[51][51];
int r, c, t;

void cleaning1(int x, int y, int p, int dir) // 윗바람
{
    if (dir != 0 && board[x][y] == -1) // 공기청정기 끝
    {
        return;
    }
    if (board[x][y] != -1)
        swap(board[x][y], p);
    int nx = x + dx1[dir];
    int ny = y + dy1[dir];
    if (0 < nx && nx <= r && 0 < ny && ny <= c)
    {
        cleaning1(nx, ny, p, dir);
    }
    else
    {
        swap(board[x][y], p);
        cleaning1(x, y, p, dir + 1);
    }
}

void cleaning2(int x, int y, int p, int dir) // 아래바람
{
    if (dir != 0 && board[x][y] == -1) // 공기청정기 끝
    {
        return;
    }
    if (board[x][y] != -1)
        swap(board[x][y], p);
    int nx = x + dx2[dir];
    int ny = y + dy2[dir];
    if (0 < nx && nx <= r && 0 < ny && ny <= c)
    {
        cleaning2(nx, ny, p, dir);
    }
    else
    {
        swap(board[x][y], p);
        cleaning2(x, y, p, dir + 1);
    }
}

void spread(int x, int y)
{
    int num = board[x][y];
    int s = board[x][y] / 5;
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx1[i];
        int ny = y + dy1[i];
        if (0 < nx && nx <= r && 0 < ny && ny <= c)
        {
            if (board[nx][ny] != -1)
            {
                tmp[nx][ny] += s;
                cnt++;
            }
        }
    }
    tmp[x][y] += num - (cnt * s);
}

int main()
{
    int ans = 0;
    pair<int, int> clean1;
    pair<int, int> clean2;
    cin >> r >> c >> t;
    bool flag = false;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> board[i][j];
            if (!flag)
            {
                if (board[i][j] == -1)
                {
                    clean1 = {i, j};
                    clean2 = {i + 1, j};
                    flag = true;
                }
            }
        }
    }
    while (t--)
    {
        memset(tmp, 0, sizeof(tmp));           // 초기화
        tmp[clean1.first][clean1.second] = -1; // 공기청정기
        tmp[clean2.first][clean2.second] = -1; // 공기정정기
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (board[i][j] != 0 && board[i][j] != -1)
                    spread(i, j);
            }
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                board[i][j] = tmp[i][j];
            }
        }
        cleaning1(clean1.first, clean1.second, 0, 0);
        cleaning2(clean2.first, clean2.second, 0, 0);
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (board[i][j] != -1)
                ans += board[i][j];
        }
    }
    cout << ans;
}
