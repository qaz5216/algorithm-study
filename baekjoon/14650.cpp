// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// long long zeroonetwo(int sum,int len)
// {
//     if(len==1)
//     {
//         if(sum%3==0)
//             return 1;
//         else
//             return 0;
//     }
//     else{
//         long long res=0;
//         for(int i=0;i<=2;i++)
//         {
//             res+=zeroonetwo(sum+i,len-1);
//         }
//         return res;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int N;
//     cin >> N;
//     int num=0;
//     for(int i=1;i<=2;i++)
//     {
//         num+=zeroonetwo(i,N);
//     }
//     cout<<num;
//     return 0;
// }

#include <iostream>
using namespace std;

int main(void)
{
    int n;
    int dp[10][3]; // dp[i][j]=i자리수 숫자중 나머지가 j가 되는 경우의수
    cin >> n;

    dp[1][0] = 0;
    dp[1][1] = 1;
    dp[1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
            // j=1이면 첫자리가 2 j=2이면 첫자리가 1 이면 된다.
            // 이때 j=0인경우를 더하는건 첫자리가 0이면 안되는경우가  i-1번째 자리수에서 빠졌음으로
            // 앞자리가 0으로 시작하는숫자를 만들고 그전 자리수와 바꿔주면 성립하는 수가 된다.
            // ex) i=3 j=0 인경우 dp[2][0]={21,12} 인데 021,012 의 자리수를 바꿔주면 201,102 성립하는 수가된다.
        }
    }

    cout << dp[n][0] << endl;
}
