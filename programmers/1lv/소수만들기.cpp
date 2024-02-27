#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
bool dp[50];
int answer;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(int cnt, int arr[3], vector<int> nums, int idx)
{
    if (cnt == 3)
    {
        int tmp = 0;
        for (int i = 0; i < 3; i++)
        {
            tmp += arr[i];
        }
        if (isPrime(tmp))
            answer++;
    }
    else
    {
        int len = nums.size();
        for (int i = idx; i < len; i++)
        {
            if (!dp[i])
            {
                arr[cnt] = nums[i];
                dp[i] = true;
                if (i + 1 <= len)
                    dfs(cnt + 1, arr, nums, i + 1);
                dp[i] = false;
            }
        }
    }
}

int solution(vector<int> nums)
{
    answer = 0;
    int arr[3];
    memset(dp, false, sizeof(dp));
    dfs(0, arr, nums, 0);
    return answer;
}