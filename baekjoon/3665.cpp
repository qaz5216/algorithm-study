#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int arr[501];
int degree[501];
vector<int> edge[501];
bool edgecheck[501][501];
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;
int main()
{
    int n, m, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            degree[i] = 0;
        }
        memset(edgecheck, false, sizeof(edgecheck));
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                // edge[i].push_back(j);
                degree[arr[j]]++;
                edgecheck[arr[i]][arr[j]] = true;
            }
        }

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (edgecheck[a][b])
            { // a<b
                degree[b]--;
                edgecheck[a][b] = false;
                // b<a
                // edge[b].push_back(a);
                edgecheck[b][a] = true;
                degree[a]++;
            }
            else
            { // b<a
                degree[a]--;
                edgecheck[b][a] = false;
                // a<b
                // edge[a].push_back(b);
                edgecheck[a][b] = true;
                degree[b]++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pq.push({degree[i], i});
        }
        int check = 0;
        vector<int> ans;
        bool flag = true;
        while (!pq.empty())
        {
            int curd = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if (curd != check)
            {
                flag = false;
                break;
            }
            ans.push_back(idx);
            check++;
        }
        if (flag)
        {
            for (int x : ans)
            {
                cout << x << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
        ans.clear();
        while (!pq.empty())
        {
            pq.pop();
        }
    }

    return 0;
}