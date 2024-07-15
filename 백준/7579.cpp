#include <iostream>

using namespace std;

int n,m;
int app[101];
int rapp[101];
int dp[101][10001];
int ans=1e9;

int main()
{
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>app[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>rapp[i];
        sum+=rapp[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<i<<","<<j<<"\n";
            if(j-rapp[i]>=0)
            {
                dp[i][j]=max(dp[i][j],dp[i-1][j-rapp[i]]+app[i]);
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }
    for (int i = 0; i <= sum; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i << endl;
			break;
		}	
	}
    return 0;
}