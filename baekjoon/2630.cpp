#include <iostream>
#include <vector>

using namespace std;

bool board[128][128]; // true 파랑 false 하양
int N;
int pa, ha;

void cal(int x, int y, int num)
{
    if (num == 1)
    {
        if (board[x][y])
            pa += 1;
        else
            ha += 1;
        return;
    }
    bool flag1 = true;
    for (int i = x; i < x + num; i++)
    {
        for (int j = y; j < y + num; j++)
        {
            if (board[i][j] != board[x][y])
                flag1 = false;
        }
    }
    if (flag1)
    {
        if (board[x][y])
            pa += 1;
        else
            ha += 1;
    }
    else
    {
        cal(x, y, num / 2);
        cal(x, y + (num / 2), num / 2);
        cal(x + (num / 2), y, num / 2);
        cal(x + (num / 2), y + (num / 2), num / 2);
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }
    pa = 0;
    ha = 0;
    cal(0, 0, N);
    cout << ha << "\n"
         << pa;
    return 0;
}