#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    int size = s.size();
    bool plus = true;
    if (s[0] == '+' || s[0] == '-')
    {
        if (s[0] == '-')
        {
            plus = false;
        }
        int cnt = 1;
        int tmp;
        while (cnt < size)
        {
            tmp = s[cnt] - '0';
            for (int i = 0; i < size - cnt - 1; i++)
            {
                tmp = tmp * 10;
            }
            answer += tmp;
            cnt++;
        }
    }
    else
    {
        int cnt = 0;
        int tmp;
        while (cnt < size)
        {
            tmp = s[cnt] - '0';
            for (int i = 0; i < size - cnt - 1; i++)
            {
                tmp = tmp * 10;
            }
            answer += tmp;
            cnt++;
        }
    }
    if (!plus)
    {
        answer = answer * (-1);
    }
    return answer;
}
/*
best Solution
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = stoi(s);
    return answer;
}
*/