#include <string>
#include <vector>
#include <cstring>
using namespace std;
int answer;
bool visit[8];
int switching(char c)
{
    int i = -1;
    if (c == 'A')
        i = 0;
    else if (c == 'C')
        i = 1;
    else if (c == 'F')
        i = 2;
    else if (c == 'J')
        i = 3;
    else if (c == 'M')
        i = 4;
    else if (c == 'N')
        i = 5;
    else if (c == 'R')
        i = 6;
    else if (c == 'T')
        i = 7;
    return i;
}

void DFS(int count, int array[], vector<string> data)
{
    if (count == 8)
    {
        for (string str : data)
        {
            int c1 = switching(str[0]);
            int c2 = switching(str[2]);
            int dist = str[4] - '0';
            char cal = str[3];
            int ic1, ic2;
            ic1 = ic2 = -1;
            for (int i = 0; i < 8; i++)
            {
                if (array[i] == c1)
                    ic1 = i;
                if (array[i] == c2)
                    ic2 = i;
            }
            if (cal == '>' && abs(ic1 - ic2) - 1 <= dist)
                return;
            if (cal == '<' && abs(ic1 - ic2) - 1 >= dist)
                return;
            if (cal == '=' && abs(ic1 - ic2) - 1 != dist)
                return;
        }
        answer++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        array[count] = i;
        DFS(count + 1, array, data);
        visit[i] = false;
    }
}

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int array[8];
    answer = 0;
    memset(visit, 0, sizeof(visit));
    memset(array, -1, sizeof(array));
    DFS(0, array, data);
    return answer;
}