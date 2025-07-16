#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r, c;
bool visit[52][52];
bool board[52][52];
priority_queue<pair<int, pair<int, int>>,
               vector<pair<int, pair<int, int>>>,
               greater<pair<int, pair<int, int>>>>
    pq;
int ans;

void print()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (board[i][j])
                cout << "L";
            else
                cout << "W";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> r >> c;
    ans = 0;
    char input;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> input;
            if (input == 'L')
            {
                board[i][j] = true;
            }
        }
    }
    // print();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (board[i][j])
            { // 점마다 bfs돌리기
                memset(visit, false, sizeof(visit));
                visit[i][j] = true;
                pq.push({0, {i, j}});
                while (!pq.empty())
                {
                    int cnt = pq.top().first;
                    int x = pq.top().second.first;
                    int y = pq.top().second.second;
                    pq.pop();
                    ans = max(ans, cnt);
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (!visit[nx][ny] && board[nx][ny])
                        {
                            pq.push({cnt + 1, {nx, ny}});
                            visit[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}