#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int arr[50][50];
int n;
int fre[50];
int cnt;
void dfs(int x, int y, int dan)
{
}

int main()
{
    cin >> n;
    int t = n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'Y')
                arr[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        memset(fre, 0, sizeof(fre));
        cnt = 0;
        fre[i] = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                if (fre[j] == 0)
                {
                    cnt++;
                    fre[j] = 1;
                }
                for (int k = 0; k < n; k++)
                {
                    if (arr[j][k] == 1 && fre[k] == 0)
                    {
                        cnt++;
                        fre[k] = 1;
                    }
                }
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans;
}