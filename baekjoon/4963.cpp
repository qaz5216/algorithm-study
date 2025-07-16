#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int arr[51][51];
int record[51][51];
int a, b;
void dfs(int y, int x)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int xx = x + i;
            int yy = y + j;
            if (xx < 0 || yy < 0 || xx >= a || yy >= b)
                ;
            else
            {
                if (record[yy][xx] == 0 && arr[yy][xx] == 1)
                {
                    record[yy][xx] = 1;
                    dfs(yy, xx);
                }
            }
        }
    }
}

int main()
{
    int result = 0;
    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (int i = 0; i < b; i++)
        {
            for (int j = 0; j < a; j++)
            {
                if (arr[i][j] == 1 && record[i][j] == 0)
                {
                    record[i][j] = 1;
                    dfs(i, j);
                    result++;
                }
            }
        }
        cout << result << "\n";
        memset(record, 0, sizeof(record));
        memset(arr, 0, sizeof(arr));
        result = 0;
    }
    return 0;
}