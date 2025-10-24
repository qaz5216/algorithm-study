#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int arr[8];
int ans[8];
bool visit[8];
void dfs(int idx)
{
    if (idx == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        ans[idx] = arr[i];
        dfs(idx + 1);
        visit[i] = false;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        visit[i] = false;
    }
    sort(arr, arr + n);
    dfs(0);
    return 0;
}