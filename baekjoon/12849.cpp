#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> edge[8];
int t;
void input()
{
    edge[0].push_back(1);
    edge[0].push_back(3);

    edge[1].push_back(0);
    edge[1].push_back(2);
    edge[1].push_back(3);

    edge[2].push_back(1);
    edge[2].push_back(3);
    edge[2].push_back(4);
    edge[2].push_back(5);

    edge[3].push_back(0);
    edge[3].push_back(1);
    edge[3].push_back(2);
    edge[3].push_back(5);

    edge[4].push_back(2);
    edge[4].push_back(5);
    edge[4].push_back(6);

    edge[5].push_back(2);
    edge[5].push_back(3);
    edge[5].push_back(4);
    edge[5].push_back(7);

    edge[6].push_back(4);
    edge[6].push_back(7);

    edge[7].push_back(6);
    edge[7].push_back(5);
    cin >> t;
}

long long dp[8][100001] = {0};

int main()
{
    input();
    dp[0][0] = 1;
    // dp[n][t]=(dp[n전길들][t-1])
    int time = 1;
    while (time <= t)
    {
        for (int i = 0; i < 8; i++)
        {
            long long sum = 0;
            for (int e : edge[i])
            {
                sum += dp[e][time - 1];
            }
            dp[i][time] = sum % 1000000007;
        }
        time++;
    }
    cout << dp[0][t];
    return 0;
}