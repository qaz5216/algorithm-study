#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    int del = 0;
    int pic = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        if (deliveries[i] != 0 || pickups[i] != 0)
        {
            long long cnt = 0;
            while (del < deliveries[i] || pic < pickups[i])
            {
                ++cnt;
                del += cap;
                pic += cap;
            }
            del -= deliveries[i];
            pic -= pickups[i];
            answer += (cnt) * (i + 1) * 2;
        }
    }

    return answer;
}
