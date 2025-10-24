#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

bool arr[101][101];
int R, C;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
bool visit[101][101];
bool visit2[101][101];
vector<pair<int, int>> tmp;
/* R=y C=x*/

void printarr()
{
    for (int i = R; i > 0; i--)
    {
        for (int j = 1; j <= C; j++)
        {
            if (arr[j][i])
                cout << "x";
            else
                cout << ".";
        }
        cout << "\n";
    }
}

void dfs(int x, int y)
{
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= C && ny <= R)
        {
            if (arr[nx][ny] && !visit[nx][ny])
            {
                dfs(nx, ny);
            }
        }
    }
}

void destory(int y)
{
    for (int i = 1; i <= C; i++)
    {
        if (arr[i][y])
        {
            arr[i][y] = false;
            break;
        }
    }
}

void destory2(int y)
{
    for (int i = C; i >= 1; i--)
    {
        if (arr[i][y])
        {
            arr[i][y] = false;
            break;
        }
    }
}

void down()
{
    int idx = 1;
    while (true)
    {
        bool flag = false;
        for (pair<int, int> p : tmp)
        {
            if (visit[p.first][p.second - (idx + 1)] || p.second - idx == 1)
            {
                flag = true;
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            idx++;
        }
    }
    for (pair<int, int> p : tmp)
    {
        arr[p.first][p.second] = false;
    }
    for (pair<int, int> p : tmp)
    {
        arr[p.first][p.second - idx] = true;
        visit[p.first][p.second - idx] = true;
    }
}

void dfs2(int x, int y)
{
    visit2[x][y] = true;
    tmp.push_back({x, y});
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx > 0 && ny > 0 && nx <= C && ny <= R)
        {
            if (arr[nx][ny] && !visit2[nx][ny])
            {
                dfs2(nx, ny);
            }
        }
    }
}

void query(int x)
{
    memset(visit, false, sizeof(visit));
    for (int j = 1; j <= C; j++)
    {
        if (arr[j][1] && !visit[j][1])
        {
            dfs(j, 1);
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (arr[j][i] && !visit[j][i])
            {
                memset(visit2, false, sizeof(visit2));
                tmp.clear();
                dfs2(j, i);
                down();
            }
        }
    }
}

int main()
{
    cin >> R >> C; /* R=y C=x*/
    for (int i = R; i > 0; i--)
    {
        for (int j = 1; j <= C; j++)
        {
            char c;
            cin >> c;
            if (c == 'x')
                arr[j][i] = true;
            else
                arr[j][i] = false;
        }
    }
    int N;
    cin >> N;
    bool turn = true;
    while (N--)
    {
        int x;
        cin >> x;
        if (turn)
        {
            destory(x);
        }
        else
        {
            destory2(x);
        }
        turn = !turn;
        query(x);
    }

    printarr();
    return 0;
}