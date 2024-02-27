#include <string>
#include <vector>

using namespace std;

string solution(string s)
{
    string answer = "";
    int len = s.size();
    int k = 1;
    for (int i = 0; i < len; i++)
    {
        string tmp;
        if (s[i] != ' ')
        {
            if (k % 2 == 1)
            {
                if (s[i] < 'a')
                    tmp = s[i];
                else
                    tmp = s[i] - ('a' - 'A');
            }
            else
            {
                if (s[i] < 'a')
                    tmp = s[i] + ('a' - 'A');
                else
                    tmp = s[i];
            }
        }
        else
        {
            tmp = s[i];
            k = 0;
        }
        answer += tmp;
        k++;
    }
    return answer;
}