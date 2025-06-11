#include <iostream>

using namespace std;

int N;
int maxnum[6];
int dp[6];
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int i=1;i<6;i++)
        {
            if(i==a||i==b)
            {
                dp[i]++;
            }
            else
            {
                if(maxnum[i]<dp[i])
                    maxnum[i]=dp[i];
                dp[i]=0;
            }
        }
    }
    for(int i=1;i<6;i++)
    {
        if(maxnum[i]<dp[i])
            maxnum[i]=dp[i];
    }
    int ansnum=0;
    int ans=5;
    for(int i=1;i<6;i++)
    {
        if(ansnum<maxnum[i])
        {
            ansnum=maxnum[i];
            ans=i;
        }
    }
    cout<<ansnum<<" "<<ans;
    return 0;
}
