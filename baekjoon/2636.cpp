#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int col, row;
bool visit[101][101];
bool table[101][101];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int remain = 0;
int tmp = 0;
void dfs(int x, int y)
{
    if (table[x][y])
    {
        tmp++;
        table[x][y] = false;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < col && 0 <= ny && ny < row)
            {
                if (!visit[nx][ny])
                {
                    visit[nx][ny] = true;
                    dfs(nx, ny);
                }
            }
        }
    }
}

int main()
{
    int time = 0;
    cin >> col >> row;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cin >> table[i][j];
            if (table[i][j])
                remain++;
        }
    }
    while (true)
    {
        memset(visit, false, sizeof(visit));
        time++;
        tmp = 0;
        visit[0][0] = true;
        dfs(0, 0);
        if (remain - tmp <= 0)
            break;
        remain -= tmp;
    }
    cout << time << "\n";
    cout << remain;
    return 0;
}