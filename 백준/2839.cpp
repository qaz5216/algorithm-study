#include <iostream>

using namespace std;

int dp[5005];

int main()
{
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=1e9;
    dp[2]=1e9;
    dp[3]=1;
    dp[4]=1e9;
    dp[5]=1;
    for(int i=6;i<=n;i++)
    {
        dp[i]=min(dp[i-5]+1,dp[i-3]+1);
    }
    if(dp[n]<1e9)
    cout<<dp[n];
    else
    cout<<-1;
    return 0;
}