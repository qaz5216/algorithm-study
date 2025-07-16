#include <iostream>
using namespace std;

bool check[7][7]; // 큰수가 앞으로
int arr[8][7];
bool visit[8][7];
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int ans = 0;

void dfs(int x, int y, int count)
{
    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 8 && ny < 7)
        {
            int a = arr[x][y];
            int b = arr[nx][ny];
            if (b > a)
                swap(a, b);
            if (!check[a][b] && !visit[nx][ny])
            {
                check[a][b] = true;
                visit[x][y] = true;
                visit[nx][ny] = true;
                for (int i = x * 7 + y; i < x * 7 + y + 14; i++)
                {
                    if (i >= 56)
                        break;
                    if (count == 27)
                    {
                        ans++;
                        break;
                    }
                    if (!visit[i / 7][i % 7])
                    {
                        dfs(i / 7, i % 7, count + 1);
                        break;
                    }
                }
                check[a][b] = false;
                visit[x][y] = false;
                visit[nx][ny] = false;
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c - '0';
        }
    }
    dfs(0, 0, 0);
    cout << ans;
    return 0;
}
