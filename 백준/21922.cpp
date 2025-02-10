#include <iostream>
#include <queue>

using namespace std;

int n,m;
int board[2001][2001];
queue<pair<int,pair<int,int>>> q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans=0;
bool can[2001][2001];
bool visit[4][2001][2001];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
            if(board[i][j]==9)
            {
                can[i][j]=true;
                for(int k=0;k<4;k++)
                {
                    q.push({k,{i,j}});
                }
            }  
        }
    }
    while(!q.empty())
    {
        pair<int,pair<int,int>>cur=q.front();q.pop();
        int x=cur.second.first;
        int y=cur.second.second;
        int d=cur.first;
        if(visit[d][x][y]) continue;
        visit[d][x][y]=true;

        can[x][y]=true;
        if(board[x][y]==0||board[x][y]==9)
        {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if(0<=nx&&nx<n&&0<=ny&&ny<m)
            {
                q.push({d,{nx,ny}});
            }
        }
        else
        {
            if(board[x][y]==1)
            {
                if(d==0||d==1)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
            }
            else if(board[x][y]==2)
            {
                if(d==2||d==3)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
            }
            else if(board[x][y]==3)
            {
                if(d==0)
                {
                    d=3;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==1)
                {
                    d=2;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==2)
                {
                    d=1;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==3)
                {
                    d=0;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
            }
            else if(board[x][y]==4)
            {
                if(d==0)
                {
                    d=2;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==1)
                {
                    d=3;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==2)
                {
                    d=0;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
                else if(d==3)
                {
                    d=1;
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(0<=nx&&nx<n&&0<=ny&&ny<m)
                    {
                        q.push({d,{nx,ny}});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(can[i][j])ans++;
        }
    }
    cout<<ans;
    return 0;
}