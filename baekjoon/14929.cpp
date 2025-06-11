#include <iostream>

using namespace std;

long long arr[100001];
long long dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dp[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=dp[i-1]+arr[i];
    }
    for(int i=1;i<n;i++)
    {
        ans+=dp[i-1]*arr[i];
    }
    cout<<ans;
    return 0;
}