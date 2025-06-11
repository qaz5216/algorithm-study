#include <iostream>

using namespace std;
int r,c;
char board[251][251];
int sheep=0;
int wolf=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visit[251][251];
int s,w;

void dfs(int x,int y)
{
    visit[x][y]=true;
    if(board[x][y]=='v')
        w++;
    if(board[x][y]=='o')
        s++;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];

        int ny=y+dy[i];
        if(0<=nx&&nx<r&&0<=ny&&ny<c)
            if(board[nx][ny]!='#'&&!visit[nx][ny])
            {
                dfs(nx,ny);
            }
    }
}

int main()
{
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>board[i][j];
            if(board[i][j]=='v')
                wolf++;
            if(board[i][j]=='o')
                sheep++;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(!visit[i][j]&&board[i][j]!='#')
            {
                s=0;
                w=0;
                dfs(i,j);
                if(s>w)
                {
                    wolf-=w;
                }
                else
                {
                    sheep-=s;
                }
            }
        }
    }
    cout<<sheep<<' '<<wolf<<'\n';
    return 0;
}