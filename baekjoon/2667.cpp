#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int arr[25][25];
int record[25][25];
int a, dan;
vector<int> result;

void dfs(int y, int x)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (abs(i) && abs(j))
                continue;
            int xx = x + i;
            int yy = y + j;
            if (xx < 0 || yy < 0 || xx >= a || yy >= a)
                ;
            else
            {
                if (record[yy][xx] == 0 && arr[yy][xx] == 1)
                {
                    record[yy][xx] = 1;
                    dan++;
                    dfs(yy, xx);
                }
            }
        }
    }
}

int main()
{
    int cnt = 0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < a; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (arr[i][j] == 1 && record[i][j] == 0)
            {
                dan = 1;
                record[i][j] = 1;
                dfs(i, j);
                result.push_back(dan);
                cnt++;
            }
        }
    }
    cout << cnt;
    sort(result.begin(), result.end());
    for (int e : result)
        cout << "\n"
             << e;
    return 0;
}