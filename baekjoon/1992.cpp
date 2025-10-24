#include <iostream>

using namespace std;
int N;
bool board[65][65];
void QuadTree(int x, int y, int num)
{
    bool check = true;
    for (int i = x; i < x + num; i++)
        for (int j = y; j < y + num; j++)
        {
            if (board[x][y] != board[i][j])
            {
                check = false;
                break;
            }
        }
    if (!check)
    {
        cout << "(";
        QuadTree(x, y, num / 2);
        QuadTree(x, y + num / 2, num / 2);
        QuadTree(x + num / 2, y, num / 2);
        QuadTree(x + num / 2, y + num / 2, num / 2);
        cout << ")";
    }
    else
    {
        cout << board[x][y];
    }
    check = true;
}

int main()
{
    cin >> N;
    char c;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> c;
            board[i][j] = c - '0';
        }

    QuadTree(0, 0, N);
    return 0;
}