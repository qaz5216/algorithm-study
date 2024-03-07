#include <iostream>

using namespace std;

int N;
int arr[100001];
int dp[100001];

int main()
{
    cin>> N;
    int result;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(i==0)
        {
            dp[0]=arr[0];
            result=dp[0];
        }
        else
        {
            dp[i]=max(dp[i-1]+arr[i],arr[i]);
            result=max(dp[i],result);
        }
    }
    cout<<result;
    return 0;
}