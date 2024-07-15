#include <iostream>
#include <vector>
using namespace std;

int arr[501][501];
int dp[501][501];
int m,n;
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
bool visit[501][501];

int dfs(int x,int y)
{
    if(x==m&&y==n) return 1;
    dp[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>0&&ny>0&&nx<=m&&ny<=n)
        {
            if(arr[x][y]>arr[nx][ny])
            {
                if(dp[nx][ny]==-1)
                    dp[x][y]+=dfs(nx,ny);
                else{
                    dp[x][y]+=dp[nx][ny];
                }
            }
        }
    }
    return dp[x][y];
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    int ans=dfs(1,1);
    cout<<ans;
    return 0;
}