#include <iostream> 

using namespace std;

int N,K;
int arr[50001];
int dp[50001][101];

int DP(int x,int count,int len)
{
    if(x<=0||count>K) return len;
    if(dp[x][count]!=0) return dp[x][count];
    int value = 0;
    if(arr[x]%2==0) value = DP(x-1,count,len+1);
    else if(count<K) value = DP(x-1,count+1,len);
    else if(count==K) return len;
    return dp[x][count]=value;
}

int main()
{
    int ans=0;
    cin>> N >> K;
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }
    for(int i=N;i>=1;i--)
    {
        for(int j=0;j<=K;j++)
        {
            if(arr[i]%2==0) ans = max(ans,DP(i,j,0));
        }
    }
    cout<<ans;
    return 0;
}