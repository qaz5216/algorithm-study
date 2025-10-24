#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int t;
bool visit[10001];
int num[10001];
int dp[10001];
int p[10001];

int calc(int n, int op) // op 1:d 2:s 3:l 4:r
{
    int result = n;
    if (op == 1)
    {
        result = (result * 2) % 10000;
    }
    else if (op == 2)
    {
        if (result == 0)
        {
            result = 9999;
        }
        else
        {
            result -= 1;
        }
    }
    else if (op == 3)
    {
        result = 0;
        int a = n / 1000;
        int b = (n % 1000) / 100;
        int c = (n % 100) / 10;
        int d = (n % 10);
        result += b * 1000;
        result += c * 100;
        result += d * 10;
        result += a;
    }
    else if (op == 4)
    {
        result = 0;
        int a = n / 1000;
        int b = (n % 1000) / 100;
        int c = (n % 100) / 10;
        int d = (n % 10);
        result += d * 1000;
        result += a * 100;
        result += b * 10;
        result += c;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        memset(visit, false, sizeof(visit));
        memset(dp, 0, sizeof(dp));
        memset(num, 0, sizeof(num));
        int a, b;
        cin >> a >> b;
        queue<int> q;
        q.push(a);
        visit[a] = true;
        bool find = false;
        while (!q.empty() && !find)
        {
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= 4; i++)
            {
                int next = calc(cur, i);
                if (!visit[next])
                {
                    dp[next] = i;
                    visit[next] = true;
                    num[next] = num[cur] + 1;
                    p[next] = cur;
                    q.push(next);
                }
                if (next == b)
                {
                    find = true;
                }
            }
        }
        vector<int> ans;
        int tmp = b;
        for (int i = 0; i < num[b]; i++)
        {
            ans.push_back(dp[tmp]);
            tmp = p[tmp];
        }
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            char op;
            if (ans[i] == 1)
                op = 'D';
            if (ans[i] == 2)
                op = 'S';
            if (ans[i] == 3)
                op = 'L';
            if (ans[i] == 4)
                op = 'R';
            cout << op;
        }
        cout << "\n";
    }
    return 0;
}