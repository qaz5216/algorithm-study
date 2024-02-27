#include <string>
#include <vector>
#include <cstring>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
// 위,아래,오른,왼
vector<string> place;
bool check = false;
bool board[5][5];
void BFS(int x, int y, int d)
{
    if (d == 0)
    {
        memset(board, true, sizeof(board));
        board[x][y] = false;
    }
    if (d == 3)
        return;
    else if (place[x][y] == 'X')
    {
        return;
    }
    else if (d != 0 && place[x][y] == 'P')
    {
        check = true;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4)
            {
                if (board[nx][ny])
                    BFS(nx, ny, d + 1);
            }
        }
    }
}

int calc(vector<string> explace)
{
    place = explace;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (place[i][j] == 'P')
            {
                BFS(i, j, 0);
                if (check)
                    return 0;
            }
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for (int i = 0; i < places.size(); i++)
    {
        check = false;
        answer.push_back(calc(places[i]));
    }
    return answer;
}