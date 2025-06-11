#include <iostream>

using namespace std;

pair<int,int> arr[101];
int dp[101][100001];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(j>=arr[i].first)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-arr[i].first]+arr[i].second);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}