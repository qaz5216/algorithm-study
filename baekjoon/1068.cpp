#include <iostream>
#include <vector>
using namespace std;

int N, X;

vector<int> arr[50];
bool check[50];
int ans = 0;
int root;

void dfs(int x)
{
    if (arr[x].size() == 0)
        ans++;
    else if (arr[x].size() == 1 && arr[x][0] == X)
    {
        ans++;
    }
    for (int i = 0; i < arr[x].size(); i++)
    {
        if (arr[x][i] != X && !check[arr[x][i]])
        {
            check[arr[x][i]] = true;
            dfs(arr[x][i]);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int par;
        cin >> par;
        if (par == -1)
        {
            root = i;
        }
        else
        {
            arr[par].push_back(i);
        }
    }
    cin >> X;
    if (X == root)
    {
        cout << 0;
        return 0;
    }
    check[root] = true;
    dfs(root);
    cout << ans;
    return 0;
}