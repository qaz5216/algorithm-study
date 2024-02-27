#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int nn;
bool cmp(string a, string b)
{
    if (a[nn] == b[nn])
    {
        return a < b;
    }
    else
    {
        return a[nn] < b[nn];
    }
}

vector<string> solution(vector<string> strings, int n)
{
    nn = n;
    vector<string> answer;
    sort(strings.begin(), strings.end(), cmp);
    answer.insert(answer.begin(), strings.begin(), strings.end());
    return answer;
}