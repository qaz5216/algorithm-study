#include <string>
#include <vector>
#include <cstring>
using namespace std;
vector<int> answer;
bool check[1000001];
void calc(int n, int x)
{
    if (check[x])
    {
        answer.push_back(x);
        for (int i = 2; i * x <= n; i++)
        {
            check[i * x] = false;
        }
    }
    if (n != x)
    {
        calc(n, x + 1);
    }
    return;
}

int solution(int n)
{
    answer.push_back(2);
    memset(check, true, sizeof(check));
    for (int i = 2; i * 2 <= n; i++)
    {
        check[i * 2] = false;
    }
    if (n > 2)
    {
        calc(n, 3);
    }
    return answer.size();
}