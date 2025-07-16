#include <iostream>

using namespace std;

int table[9][9];
bool row[9][10];
bool col[9][10];
bool nemo[9][10];
void dfs(int num)
{
    if (num == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << table[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    else
    {
        int x = num / 9;
        int y = num % 9;
        if (table[x][y] == 0)
        {
            for (int i = 1; i < 10; i++)
            {
                if (row[x][i] == false && col[y][i] == false && nemo[(x / 3) * 3 + (y / 3)][i] == false)
                {
                    row[x][i] = true;
                    col[y][i] = true;
                    nemo[(x / 3) * 3 + (y / 3)][i] = true;
                    table[x][y] = i;
                    dfs(num + 1);
                    row[x][i] = false;
                    col[y][i] = false;
                    nemo[(x / 3) * 3 + (y / 3)][i] = false;
                    table[x][y] = 0;
                }
            }
        }
        else
        {
            dfs(num + 1);
        }
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++)
        {
            table[i][j] = s[j] - '0';
            if (table[i][j] != 0)
            {
                row[i][table[i][j]] = true;
                col[j][table[i][j]] = true;
                nemo[(i / 3) * 3 + (j / 3)][table[i][j]] = true;
            }
        }
    }
    dfs(0);
    return 0;
}