#include <iostream>

using namespace std;

#define ll long long

ll INF = 1e9 + 9;
int T;
int dp1[100001];
int dp2[100001];

int main()
{
    cin >> T;
    dp1[1] = 1;
    dp2[1] = 0;
    dp1[2] = 1;
    dp2[2] = 1;
    dp1[3] = 2;
    dp2[3] = 2;
    for (int i = 4; i <= 100000; i++)
    {
        dp1[i] = ((ll)dp2[i - 1] + (ll)dp2[i - 2] + (ll)dp2[i - 3]) % INF;
        dp2[i] = ((ll)dp1[i - 1] + (ll)dp1[i - 2] + (ll)dp1[i - 3]) % INF;
    }
    while (T--)
    {
        int a;
        cin >> a;
        cout << dp1[a] << " " << dp2[a] << "\n";
    }
    return 0;
}

/*          홀수    짝수
1   1개     1개     0개

2   2개     홀수    짝수
2           1개     1개
1 1

3   4개     홀수    짝수
3           2개     2개
2 1
1 2
1 1 1

4   7개     홀수    짝수
3 1         3개     4개
1 3
2 2
2 1 1
1 2 1
1 1 2
1 1 1 1

5 13 개     홀수    짝수
3 2         7개     6개
3 1 1
2 3
2 2 1
2 1 2
2 1 1 1
1 3 1
1 2 2
1 2 1 1
1 1 3
1 1 2 1
1 1 1 2
1 1 1 1 1

dp[i]=dp[i-1]+dp[i-2]+dp[i-3]

dp[7]=22+22=44

dp[6]=13+7+4=24 이라면
dp[7]=24+13+7=44

dp[10]=137+137=274

dp[8]=44+24+13=81
dp[9]=81+44+24=68+81=149
dp[10]=149+81+44=274 확인

dp[i]=dp[i-1]+dp[i-2]+dp[i-3] 정답

홀수 짝수?

홀수 짝수에 대해서
dp[i]=dp[i-1]+dp[i-2]+dp[i-3] 성립x

dp1[i]=dp2[i-1]+dp2[i-2]+dp2[i-3]
dp2[i]=dp1[i-1]+..... 성립

*/