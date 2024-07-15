#include <iostream>

using namespace std;

int dp[1000001];
int p[1000001];

int main()
{
    int n;
    cin>>n;
    dp[1]=0;
    dp[2]=1;
    p[2]=1;
    dp[3]=1;
    p[3]=1;
    for(int i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+1;
        p[i]=i-1;
        if(i%3==0){
            if(dp[i]>dp[i/3]+1)
                p[i]=i/3;
            dp[i]=min(dp[i],dp[i/3]+1);
        }
        if(i%2==0){
            if(dp[i]>dp[i/2]+1)
                p[i]=i/2;
            dp[i]=min(dp[i],dp[i/2]+1);
        }
    }
    cout<<dp[n]<<"\n";
    while(true)
    {
        cout<<n<<" ";
        if(n<=1)
        break;
        n=p[n];
    }
    return 0;
}