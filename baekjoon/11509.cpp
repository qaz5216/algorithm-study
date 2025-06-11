#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1000001];
int dp[1000001];
int main()
{
    int n,mx=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[arr[i]+1]>0)
        {
            dp[arr[i]+1]--;
            dp[arr[i]]++;
        }
        else
        {
            ans++;
            dp[arr[i]]++;
        }
    }
    cout<<ans;
    return 0;
}