#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool board[51][51];
int visit[51][51];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            board[i][j] = x - '0';
            visit[i][j] = -1;
        }
    }
    visit[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        // cout<<"now="<<now.first<<","<<now.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                // cout<<" next="<<nx<<","<<ny<<" ";
                if (visit[nx][ny] == -1)
                {
                    // cout<<" firstvisit";
                    if (!board[nx][ny])
                    {
                        visit[nx][ny] = visit[now.first][now.second] + 1;
                        q.push({nx, ny});
                    }
                    else
                    {
                        visit[nx][ny] = visit[now.first][now.second];
                        q.push({nx, ny});
                    }
                }
                else
                {
                    // cout<<" visit";
                    if (!board[nx][ny])
                    {
                        if (visit[nx][ny] > visit[now.first][now.second] + 1)
                        {
                            visit[nx][ny] = visit[now.first][now.second] + 1;
                            q.push({nx, ny});
                        }
                    }
                    else if (visit[nx][ny] > visit[now.first][now.second])
                    {
                        visit[nx][ny] = visit[now.first][now.second];
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << visit[n - 1][n - 1];
    return 0;
}