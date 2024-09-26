#include <iostream>
#include <queue>
using namespace std;
int n,m,h,w;
bool flag=false;
bool check[1001][1001];
bool board[1001][1001];
int gx,gy;
int mn=10000001;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool gosquare(int x,int y,int op)
{
    if(check[x][y]) return false;
    if(op==0)
    {
        if(x+h-1>n) return false;
        for(int j=y;j<y+w;j++)
        {
            if(board[x+h-1][j])
                return false;
        }
    }
    if(op==1)
    {
        if(x<1) return false;
        for(int j=y;j<y+w;j++)
        {
            if(board[x][j])
                return false;
        }
        
    }
    if(op==2)
    {
        if(y+w-1>m) return false;
        for(int i=x;i<x+h;i++)
        {
            if(board[i][y+w-1])
                return false;
        }
    }
    if(op==3)
    {
        if(y<1) return false;
        for(int i=x;i<x+h;i++)
        {
            if(board[i][y])
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>board[i][j];
        }
    }

    int sx,sy;
    cin>>h>>w>>sx>>sy>>gx>>gy;
    check[sx][sy]=true;
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{sx,sy}});
    while(!q.empty())
    {
        pair<int,pair<int,int>> cur=q.front();q.pop();
        if(cur.first>mn) continue;
        int curx=cur.second.first;
        int cury=cur.second.second;
        if(curx==gx&&cury==gy)
        {
            cout<<cur.first;
            return 0;
        }
        for(int i=0;i<4;i++)
        {
            int nx=curx+dx[i];
            int ny=cury+dy[i];
            if(gosquare(nx,ny,i))
            {
                check[nx][ny]=true;
                q.push({cur.first+1,{nx,ny}});
            }
        }
    }
        
    cout<<-1;
    return 0;
}