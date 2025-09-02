#include <iostream>

using namespace std;

int n;

bool board[65][65];

void quad(int x, int y, int num)
{
    bool tmp = board[x][y];
    bool flag = true;
    for (int i = x; i < x + num; i++)
    {
        for (int j = y; j < y + num; j++)
        {
            if (board[i][j] != tmp)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag)
    {
        cout << tmp;
    }
    else
    {
        cout << "(";
        int num2 = num / 2;
        quad(x, y, num2);
        quad(x, y + num2, num2);
        quad(x + num2, y, num2);
        quad(x + num2, y + num2, num2);
        cout << ")";
    }
}

int main()
{
    cin >> n;
    char c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    quad(0, 0, n);
    return 0;
}