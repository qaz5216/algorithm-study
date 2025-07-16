#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr[101];
int record[101];
int result = 0;
void dfs(int n)
{
    for (int e : arr[n])
    {
        if (record[e] == 0)
        {
            record[e] = 1;
            dfs(e);
            result++;
        }
    }
}
int main()
{
    int n, m, a, b;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    record[1] = 1;
    dfs(1);
    cout << result;
    return 0;
}