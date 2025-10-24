#include <iostream>
#include <queue>
using namespace std;

int m, n;
bool board[102][102];    // y,x
bool visit[4][102][102]; // 방향y,x
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
//         동 북 서 남
priority_queue<
    pair<int, pair<int, pair<int, int>>>,
    vector<pair<int, pair<int, pair<int, int>>>>,
    greater<pair<int, pair<int, pair<int, int>>>>>
    pq;

int turnleft(int dir)
{
    return (dir + 1) % 4;
}
int turnright(int dir)
{
    return (dir + 3) % 4; //((dir-1)+4)%4
}

int inputdirchange(int dir)
{
    switch (dir)
    {
    case 1:
        dir = 0;
        break;
    case 2:
        dir = 2;
        break;
    case 3:
        dir = 3;
        break;
    case 4:
        dir = 1;
        break;
    default:
        break;
    }
    return dir;
}

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> board[i][j];
            board[i][j] = !board[i][j];
        }
    }
    int sx, sy, sdir;
    int ex, ey, edir;
    cin >> sy >> sx >> sdir;
    cin >> ey >> ex >> edir;
    sdir = inputdirchange(sdir);
    edir = inputdirchange(edir);
    visit[sdir][sy][sx] = true;
    pq.push({0, {sdir, {sy, sx}}});
    int cnt, dir, x, y;
    while (!pq.empty())
    {
        cnt = pq.top().first;
        dir = pq.top().second.first;
        y = pq.top().second.second.first;
        x = pq.top().second.second.second;
        pq.pop();
        if (x == ex && y == ey && dir == edir)
        {
            cout << cnt;
            break;
        }
        // 방향전진
        bool flag = true; // 한번막히면 더전진못하니까
        for (int i = 1; i <= 3; i++)
        { // 전진 1,2,3칸
            if (!flag)
                break;
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (board[ny][nx])
            { // 방문했어도 다음칸 전진은 할수있지않나
                if (!visit[dir][ny][nx])
                {
                    visit[dir][ny][nx] = true;
                    pq.push({cnt + 1, {dir, {ny, nx}}});
                }
            }
            else
            {
                flag = false;
            }
        }
        // 왼쪽으로 돌리기
        int ndir = turnleft(dir);
        if (!visit[ndir][y][x])
        {
            visit[ndir][y][x] = true;
            pq.push({cnt + 1, {ndir, {y, x}}});
        }
        // 오른쪽으로 돌리기
        ndir = turnright(dir);
        if (!visit[ndir][y][x])
        {
            visit[ndir][y][x] = true;
            pq.push({cnt + 1, {ndir, {y, x}}});
        }
    }
    return 0;
}

/*
방향: 문제에선 동쪽 1 서쪽 2 남쪽 3 북쪽 4
         나는 동쪽0 북1 서2 남3 으로 쓸거임



        pop = goal;

         for direction
            for 1 ~ 3
                if()
                    push
 q안에는 제자리 도는 행동이 없다.

*/