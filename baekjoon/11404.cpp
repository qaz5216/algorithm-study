#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
#define INF 10000001;
int map[102][102];

void printmap()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j || map[i][j] == 10000001)
            {
                cout << "0" << " ";
            }
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve()
{
    for (vector<int> bus : arr)
    {
        if (map[bus[0]][bus[1]] > bus[2])
        {
            map[bus[0]][bus[1]] = bus[2];
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                if (map[j][i] != 10000001 && map[i][k] != 10000001)
                {
                    map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
                }
            }
}

int main()
{
    cin >> n;
    cin >> m;
    // 초기화
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = INF;
        }
    }
    // solve
    for (int i = 0; i < m; i++)
    {
        vector<int> tmp;
        int a, b, c;
        cin >> a >> b >> c;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        arr.push_back(tmp);
    }
    solve();
    // print
    printmap();
    return 0;
}