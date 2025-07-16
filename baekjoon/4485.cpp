#include <iostream>
#include <queue>

using namespace std;
int n;
int board[125][125];
int dp[125][125];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

int main()
{
    int t = 1;
    while (true)
    {
        int ans;
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j] = 1e9;
        }
        pq.push({board[0][0], {0, 0}});
        bool flag = false;
        while (!pq.empty())
        {
            if (flag)
            {
                pq.pop();
                continue;
            }
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();
            if (x == n - 1 && y == n - 1)
            {
                flag = true;
                ans = cost;
                continue;
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n)
                {
                    if (dp[nx][ny] > cost + board[nx][ny])
                    {
                        pq.push({cost + board[nx][ny], {nx, ny}});
                        dp[nx][ny] = cost + board[nx][ny];
                    }
                }
            }
        }
        cout << "Problem " << t << ": " << ans << "\n";
        t++;
    }
    return 0;
}