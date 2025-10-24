#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int cube[6][9];

void initcube()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 9; j++)
            cube[i][j] = i;
    }
}

char color(int x)
{
    char a = '0' + x;
    if (a == '0')
        a = 'w'; // 위
    else if (a == '1')
        a = 'y'; // 아래
    else if (a == '2')
        a = 'r'; // 앞
    else if (a == '3')
        a = 'o'; // 뒤
    else if (a == '4')
        a = 'g'; // 왼
    else if (a == '5')
        a = 'b'; // 오
    return a;
}

void Secturn(int idx, bool op)
{
    int tmp[9];
    for (int i = 0; i < 9; i++)
    {
        tmp[i] = cube[idx][i];
    }
    if (op)
    {
        cube[idx][0] = tmp[6];
        cube[idx][1] = tmp[3];
        cube[idx][2] = tmp[0];
        cube[idx][3] = tmp[7];
        cube[idx][4] = tmp[4];
        cube[idx][5] = tmp[1];
        cube[idx][6] = tmp[8];
        cube[idx][7] = tmp[5];
        cube[idx][8] = tmp[2];
    }
    else
    {
        cube[idx][0] = tmp[2];
        cube[idx][1] = tmp[5];
        cube[idx][2] = tmp[8];
        cube[idx][3] = tmp[1];
        cube[idx][4] = tmp[4];
        cube[idx][5] = tmp[7];
        cube[idx][6] = tmp[0];
        cube[idx][7] = tmp[3];
        cube[idx][8] = tmp[6];
    }
}

void Turn(char tar, char op)
{
    vector<int> src;
    vector<vector<int>> move;
    if (tar == 'U')
    {
        if (op == '+')
        {
            // 앞->왼->뒤->오->앞
            src.push_back(2);
            src.push_back(4);
            src.push_back(3);
            src.push_back(5);
            /*
            src[2][0,1,2] 움직여.
            src[4][0,1,2] 움직여.
            src[3][0,1,2] 움직여.
            src[5][0,1,2] 움직여.
            */
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            Secturn(0, true);
        }
        else
        {
            // 앞->오->뒤->왼->앞
            src.push_back(2);
            src.push_back(5);
            src.push_back(3);
            src.push_back(4);
            /*
            src[2][0,1,2] 움직여.
            src[5][0,1,2] 움직여.
            src[3][0,1,2] 움직여.
            src[4][0,1,2] 움직여.
            */
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            move.push_back({0, 1, 2});
            Secturn(0, false);
        }
    }
    if (tar == 'D')
    {
        if (op == '+')
        {
            // 앞->오->뒤->왼->앞
            src.push_back(2);
            src.push_back(5);
            src.push_back(3);
            src.push_back(4);
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            Secturn(1, true);
        }
        else
        {
            // 앞->왼->뒤->오->앞
            src.push_back(2);
            src.push_back(4);
            src.push_back(3);
            src.push_back(5);
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            move.push_back({6, 7, 8});
            Secturn(1, false);
        }
    }
    if (tar == 'F')
    {
        if (op == '+')
        {
            // 위->오->아->왼->위
            src.push_back(0);
            src.push_back(5);
            src.push_back(1);
            src.push_back(4);
            move.push_back({6, 7, 8});
            move.push_back({0, 3, 6});
            move.push_back({2, 1, 0});
            move.push_back({8, 5, 2});
            Secturn(2, true);
        }
        else
        {
            // 위->왼->아->오->위
            src.push_back(0);
            src.push_back(4);
            src.push_back(1);
            src.push_back(5);
            /*
            src[0][6,7,8] 움직여.
            src[4][2,5,8] 움직여.
            src[1][0,1,2] 움직여.
            src[5][0,3,6] 움직여.
            */
            move.push_back({6, 7, 8});
            move.push_back({8, 5, 2});
            move.push_back({2, 1, 0});
            move.push_back({0, 3, 6});
            Secturn(2, false);
        }
    }
    if (tar == 'B')
    {
        if (op == '+')
        {
            // 위->왼->아->오->위
            src.push_back(0);
            src.push_back(4);
            src.push_back(1);
            src.push_back(5);
            /*
            src[0][0,1,2] 움직여.
            src[4][0,3,6] 움직여.
            src[1][6,7,8] 움직여.
            src[5][2,5,8] 움직여.
            */
            move.push_back({0, 1, 2});
            move.push_back({6, 3, 0});
            move.push_back({8, 7, 6});
            move.push_back({2, 5, 8});
            Secturn(3, true);
        }
        else
        {
            // 위->오->아->왼->위
            src.push_back(0);
            src.push_back(5);
            src.push_back(1);
            src.push_back(4);
            /*
            src[0][0,1,2] 움직여.
            src[5][2,5,8] 움직여.
            src[1][6,7,8] 움직여.
            src[4][0,3,6] 움직여.
            */
            move.push_back({0, 1, 2});
            move.push_back({2, 5, 8});
            move.push_back({8, 7, 6});
            move.push_back({6, 3, 0});
            Secturn(3, false);
        }
    }
    if (tar == 'L')
    {
        if (op == '+')
        {
            // 위->앞->아->뒤->위
            src.push_back(0);
            src.push_back(2);
            src.push_back(1);
            src.push_back(3);
            /*
            src[0][0,3,6] 움직여.
            src[2][0,3,6] 움직여.
            src[1][0,3,6] 움직여.
            src[3][2,5,8] 움직여.
            */
            move.push_back({0, 3, 6});
            move.push_back({0, 3, 6});
            move.push_back({0, 3, 6});
            move.push_back({8, 5, 2});
            Secturn(4, true);
        }
        else
        {
            // 위->뒤->아->앞->위
            src.push_back(0);
            src.push_back(3);
            src.push_back(1);
            src.push_back(2);
            /*
            src[0][0,3,6] 움직여.
            src[3][2,5,8] 움직여.
            src[1][0,3,6] 움직여.
            src[2][0,3,6] 움직여.
            */
            move.push_back({0, 3, 6});
            move.push_back({8, 5, 2});
            move.push_back({0, 3, 6});
            move.push_back({0, 3, 6});
            Secturn(4, false);
        }
    }
    if (tar == 'R')
    {
        if (op == '+')
        {
            // 위->뒤->아->앞->위
            src.push_back(0);
            src.push_back(3);
            src.push_back(1);
            src.push_back(2);
            /*
            src[0][2,5,8] 움직여.
            src[3][0,3,6] 움직여.
            src[1][2,5,8] 움직여.
            src[2][2,5,8] 움직여.
            */
            move.push_back({2, 5, 8});
            move.push_back({6, 3, 0});
            move.push_back({2, 5, 8});
            move.push_back({2, 5, 8});
            Secturn(5, true);
        }
        else
        {
            // 위->앞->아->뒤->위
            src.push_back(0);
            src.push_back(2);
            src.push_back(1);
            src.push_back(3);
            /*
            src[0][2,5,8] 움직여.
            src[2][2,5,8] 움직여.
            src[1][2,5,8] 움직여.
            src[3][0,3,6] 움직여.
            */
            move.push_back({2, 5, 8});
            move.push_back({2, 5, 8});
            move.push_back({2, 5, 8});
            move.push_back({6, 3, 0});
            Secturn(5, false);
        }
    }
    int tmp[3];
    tmp[0] = cube[src[3]][move[3][0]];
    tmp[1] = cube[src[3]][move[3][1]];
    tmp[2] = cube[src[3]][move[3][2]];
    for (int i = 3; i > 0; i--)
    {
        cube[src[i]][move[i][0]] = cube[src[i - 1]][move[i - 1][0]];
        cube[src[i]][move[i][1]] = cube[src[i - 1]][move[i - 1][1]];
        cube[src[i]][move[i][2]] = cube[src[i - 1]][move[i - 1][2]];
    }
    cube[src[0]][move[0][0]] = tmp[0];
    cube[src[0]][move[0][1]] = tmp[1];
    cube[src[0]][move[0][2]] = tmp[2];
}

int T;

int main()
{
    cin >> T;
    while (T--)
    {
        initcube();
        int n;
        cin >> n;
        while (n--)
        {
            char cmd[3];
            cin >> cmd;
            Turn(cmd[0], cmd[1]);
        }
        cout << color(cube[0][0]) << color(cube[0][1]) << color(cube[0][2]) << "\n";
        cout << color(cube[0][3]) << color(cube[0][4]) << color(cube[0][5]) << "\n";
        cout << color(cube[0][6]) << color(cube[0][7]) << color(cube[0][8]) << "\n";
    }
    return 0;
}