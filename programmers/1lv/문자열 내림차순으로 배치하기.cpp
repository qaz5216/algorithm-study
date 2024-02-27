#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(char a, char b)
{
    if (a - 'a' == b - 'A')
    {
        return a > b;
    }
    else if (a - 'A' == b - 'a')
    {
        return b < a;
    }
    return a > b;
}

string solution(string s)
{
    string answer = "";
    sort(s.begin(), s.end(), cmp);
    return s;
}