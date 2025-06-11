/* dijkstra solution
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool visit[101][101];
bool board[101][101];
int dp[101][101];
int n,m;

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            board[i][j]=s[j-1]-'0';
        }
    }
    memset(dp,-1,sizeof(dp));
    visit[1][1]=true;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{1,1}});
    dp[1][1]=0;
    while (!pq.empty())
    {
        pair<int,pair<int,int>> cur=pq.top();pq.pop();
        for(int i=0;i<4;i++)
        {
            int nx=cur.second.first+dx[i];
            int ny=cur.second.second+dy[i];
            if(0<nx&&nx<=n&&0<ny&&ny<=m)
            {
                if(dp[nx][ny]==-1)
                {
                    if(board[nx][ny])
                    {
                        dp[nx][ny]=cur.first+1;
                        pq.push({cur.first+1,{nx,ny}});
                    }
                    else
                    {
                        dp[nx][ny]=cur.first;
                        pq.push({cur.first,{nx,ny}});
                    }
                }
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
*/

/* dfs solution
#include <iostream>
#include <cstring>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool visit[101][101];
bool board[101][101];
int dp[101][101];
int n,m;

void dfs(int x,int y,int aoj)
{
    dp[x][y]=aoj;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<nx&&nx<=n&&0<ny&&ny<=m)
            if(!visit[nx][ny])
            {
                visit[nx][ny]=true;
                if(board[nx][ny]){
                    if(dp[nx][ny]==-1){
                        dfs(nx,ny,aoj+1);
                    }

                    else if(dp[nx][ny]>aoj+1){
                        dfs(nx,ny,aoj+1);
                    }
                }
                else{
                    if(dp[nx][ny]==-1){
                        dfs(nx,ny,aoj);
                    }
                    else if(dp[nx][ny]>aoj){
                        dfs(nx,ny,aoj);
                    }
                }
                visit[nx][ny]=false;
            }
    }
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=1;j<=m;j++)
        {
            board[i][j]=s[j-1]-'0';
        }
    }
    memset(dp,-1,sizeof(dp));
    visit[1][1]=true;
    dfs(1,1,0);
    cout<<dp[n][m];
    
    return 0;
}
*/