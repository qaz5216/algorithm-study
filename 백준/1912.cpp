#include <iostream>

using namespace std;

int N;
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>> N;
    int result;
    for(int i=0;i<N;i++)
    {
        cin>>dp[i];
        if(i==0)
        {
            result=dp[0];
        }
        else
        {
            dp[i]=max(dp[i-1]+dp[i],dp[i]);
            result=max(dp[i],result);
        }
    }
    cout<<result;
    return 0;
}