#include <iostream>

using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];

int main()
{   
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        dp1[i]=1;
        dp2[n-1-i]=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp1[i]=max(dp1[i],dp1[j]+1);
            }
            if(arr[n-1-j]<arr[n-1-i])
            {
                dp2[n-1-i]=max(dp2[n-1-i],dp2[n-1-j]+1);
            }
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        result=max(result,dp1[i]+dp2[i]-1);
    }
    cout<<result;
    return 0;
}