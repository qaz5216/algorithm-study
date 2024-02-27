#include <string>
#include <vector>

using namespace std;
long long sum;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = -2;
    int len;
    sum = 0;
    for (int i : queue1)
    {
        sum += i;
    }
    long long left = sum;
    for (int i : queue2)
    {
        sum += i;
    }
    if (sum % 2 == 1)
        return -1;
    long long right = sum - left;
    len = queue1.size() + queue2.size();
    int li = 0, ri = 0;
    bool lcheck = true;
    bool rcheck = true;
    for (int i = 0; i < len * 2; i++)
    {
        if (left > right)
        {
            if (li >= len / 2)
            {
                li = 0;
                lcheck = !lcheck;
            }
            if (lcheck)
            {
                left -= queue1[li];
                right += queue1[li];
                li++;
            }
            else
            {
                left -= queue2[li];
                right += queue2[li];
                li++;
            }
        }
        else if (right > left)
        {
            if (ri >= len / 2)
            {
                ri = 0;
                rcheck = !rcheck;
            }
            if (rcheck)
            {
                right -= queue2[ri];
                left += queue2[ri];
                ri++;
            }
            else
            {
                right -= queue1[ri];
                left += queue1[ri];
                ri++;
            }
        }
        else
        {
            return i;
        }
    }
    return -1;
}