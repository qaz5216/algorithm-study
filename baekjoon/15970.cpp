#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[100001];
vector<int> v[100001];
vector<int> color;

using namespace std;

long long ans = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        if (!visit[b])
        {
            visit[b] = true;
            color.push_back(b);
        }
    }
    for (int i = 0; i < color.size(); i++)
    {
        sort(v[color[i]].begin(), v[color[i]].end());
    }
    for (int i = 0; i < color.size(); i++)
    {
        if (v[color[i]].size() <= 1)
            continue;
        for (int j = 0; j < v[color[i]].size(); j++)
        {
            int left;
            int right;
            if (j == 0)
            {
                left = 1e9;
            }
            else
            {
                left = v[color[i]][j] - v[color[i]][j - 1];
            }
            if (j == v[color[i]].size() - 1)
            {
                right = 1e9;
            }
            else
            {
                right = v[color[i]][j + 1] - v[color[i]][j];
            }
            ans += min(left, right);
        }
    }
    cout << ans;
}