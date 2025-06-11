#include <iostream>
#include <vector>

using namespace std;

int ans=0;
int arr[1001];
int dp[1001];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
            if(i==j)
            {
                dp[i]=max(dp[i],1);
            }
        }
    }
    return 0;
}