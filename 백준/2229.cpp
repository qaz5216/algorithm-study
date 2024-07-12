#include <iostream>

using namespace std;

int N;
int score[1001];
int dp[1001];
int mx,mn;

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>score[i];
    }
    for(int i=0;i<N;i++)
    {
        mx=mn=score[i];
        for(int j=i;j>=0;j--)
        {
            mx=max(mx,score[j]);
            mn=min(mn,score[j]);
            dp[i+1]=max(dp[i+1],dp[j]+mx-mn);
        }
    }
    cout<<dp[N];
    return 0;
}