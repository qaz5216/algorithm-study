#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
int ans[16];
bool visit[8];
bool find = false;

void dfs(int idx)
{
    if (idx == N * 2)
    {
        for (int i = 0; i < N * 2; i++)
        {
            cout << ans[i] << " ";
        }
        exit(0);
    }
    if (ans[idx] != -1)
    {
        dfs(idx + 1);
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (ans[idx + arr[i] + 1] != -1 || visit[i])
            {
                continue;
            }
            visit[i] = true;
            ans[idx] = arr[i];
            ans[idx + arr[i] + 1] = arr[i];
            dfs(idx + 1);
            visit[i] = false;
            ans[idx] = -1;
            ans[idx + arr[i] + 1] = -1;
        }
    }
    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N * 2; i++)
    {
        ans[i] = -1;
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
    cout << "-1";
    return 0;
}