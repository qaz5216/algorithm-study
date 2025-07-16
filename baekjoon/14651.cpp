#include <iostream>
using namespace std;

int main(void)
{
    int n;
    long long dp[33334][3]; // dp[i][j]=i자리수 숫자중 나머지가 j가 되는 경우의수
    long long MAX = 1e9 + 9;
    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MAX;
        }
    }

    cout << dp[n][0] << endl;
}
