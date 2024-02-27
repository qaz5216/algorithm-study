#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(1);
    }
    for (int i = 0; i < lost.size(); i++)
    {
        arr[lost[i] - 1] = 0;
    }
    for (int i = 0; i < reserve.size(); i++)
    {
        arr[reserve[i] - 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (i != 0 && i != n - 1)
            {
                if (arr[i - 1] == 2)
                {
                    arr[i - 1] = 1;
                    arr[i] = 1;
                }
                else if (arr[i + 1] == 2)
                {
                    arr[i + 1] = 1;
                    arr[i] = 1;
                }
            }
            else if (i == 0)
            {
                if (arr[i + 1] == 2)
                {
                    arr[i + 1] = 1;
                    arr[i] = 1;
                }
            }
            else
            {
                if (arr[i - 1] == 2)
                {
                    arr[i - 1] = 1;
                    arr[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            answer++;
    }
    return answer;
}