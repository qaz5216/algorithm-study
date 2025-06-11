#include <iostream>

using namespace std;

int dp[301];
int arr[301];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    dp[1]=arr[1];
    dp[2]=dp[1]+arr[2];
    for(int i=3;i<=n;i++)
    {
        dp[i]=max(dp[i-3]+arr[i-1],dp[i-2])+arr[i];
    }
    cout<<dp[n];
    return 0;
}
/*
dp[1]=10;
dp[2]=10+20=30;
dp[3]=20+15=35;
dp[4]=dp[1]+arr[3]+arr[4] or dp[2]+arr[4]; 
*/