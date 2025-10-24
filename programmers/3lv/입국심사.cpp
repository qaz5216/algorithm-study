#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    int mt=0;
    for(int t:times)
    {
        mt=max(mt,t);
    }
    long long s = 0;
    long long e = n *(long long)mt;

    while (s <= e) {

        long long mid = (s + e) / 2;
        long long tmp = 0;

        for (int t:times) {
            tmp += mid / (long long)t;
        }

        if (tmp >= n) {
            e = mid - 1;
            answer = mid;
        }
        else s = mid + 1;
    }
    return answer;
}