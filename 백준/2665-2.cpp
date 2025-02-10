#include <iostream> 
#include <cstring>
#include <queue>
using namespace std;

int n;
bool board[51][51];
int dp[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n;j++)
        {
            char x;
            cin>>x;
            board[i][j]=x-'0';
        }
    }
    memset(dp,-1,sizeof(dp));
    priority_queue<pair<int,pair<int,int>>> pq;
    dp[0][0]=0;
    pq.push({0,{0,0}});
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int curx=pq.top().second.first;
        int cury=pq.top().second.second;
        pq.pop();
        if(dp[curx][cury]!=-1&&dist>dp[curx][cury]) continue;
        for(int i=0;i<4;i++)
        {
            int nx=curx+dx[i];
            int ny=cury+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<n)
            {
                int tmp=0;
                if(board[nx][ny]==0)tmp=1;
                if(dp[nx][ny]==-1)
                {
                    pq.push({dist+tmp,{nx,ny}});
                    dp[nx][ny]=dist+tmp;
                }
                else
                {
                    if(dp[nx][ny]>dist+tmp)
                    {
                        pq.push({dist+tmp,{nx,ny}});
                        dp[nx][ny]=dist+tmp;
                    }
                }
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}