#include <iostream>
#include <queue>
using namespace std;

int n, k;

int dp[100001];
int p[100001];
bool visit[100001];
vector<int> v;
int ans = 0;

int main()
{
    cin >> n >> k;
    if (n == k)
    {
        cout << 0 << "\n"
             << n;
        return 0;
    }
    queue<int> q;
    q.push(n);
    bool find = false;
    while (!q.empty() && !find)
    {
        int cur = q.front();
        q.pop();
        int next[3] = {cur - 1, cur + 1, cur * 2};
        for (int i = 0; i < 3; i++)
        {
            if (0 <= next[i] && next[i] <= 100000 && !visit[next[i]])
            {
                q.push(next[i]);
                visit[next[i]] = true;
                dp[next[i]] = dp[cur] + 1;
                p[next[i]] = cur;
            }
            if (next[i] == k)
            {
                ans = dp[next[i]];
                find = true;
            }
        }
    }
    cout << ans << "\n";
    v.push_back(k);
    for (int i = 0; i < ans; i++)
    {
        v.push_back(p[k]);
        k = p[k];
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << " ";
    }
    return 0;
}