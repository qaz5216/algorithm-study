#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool arr[1000001];
vector<int> v;
void check(int k, int n)
{
    for (int i = 1; i <= n / k; i++)
        arr[i * k] = true;
}

int solution(int n)
{
    memset(arr, false, sizeof(arr));
    arr[1] = true;
    arr[0] = true;
    arr[2] = true;
    v.push_back(2);
    for (int i = 2; i <= n / 2; i++)
    {
        arr[i * 2] = true;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!arr[i])
        {
            v.push_back(i);
            check(i, n);
        }
    }
    return v.size();
}