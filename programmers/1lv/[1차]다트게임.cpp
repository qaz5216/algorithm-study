#include <string>

using namespace std;
int coin(char a)
{
    if (a == 'S')
        return 1;
    else if (a == 'D')
        return 2;
    else
        return 3;
}

int solution(string dartResult)
{
    int answer = 0;
    int len = dartResult.size();
    int num;
    int sq;
    int eex = 4001;
    int ex = 4001;
    for (int i = 0; i < len; i++)
    {
        if ('0' <= dartResult[i] && dartResult[i] <= '9')
        {
            if (dartResult[i] != '1')
                num = dartResult[i] - '0';
            else
            {
                if (dartResult[i + 1] == '0')
                {
                    num = 10;
                    i++;
                }
                else
                    num = 1;
            }
        }
        else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T')
        {
            sq = coin(dartResult[i]);
            int tmp = num;
            for (int j = 1; j < sq; j++)
            {
                tmp = tmp * num;
            }
            answer += tmp;
            eex = ex;
            ex = tmp;
        }
        else
        {
            if (dartResult[i] == '#')
            {
                answer -= ex * 2;
                ex = (-1) * ex;
            }
            else
            {
                if (eex == 4001)
                {
                    answer += ex;
                    ex = ex * 2;
                }
                else
                {
                    answer += ex;
                    answer += eex;
                    ex = ex * 2;
                    eex = eex * 2;
                }
            }
        }
    }
    return answer;
}