#include <iostream>
#include <cstring>
using namespace std;
int n;
char arr[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x,int y)
{
    visit[x][y]=true;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<n)
        {
            if(!visit[nx][ny]&&arr[nx][ny]==arr[x][y])
            {
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]) continue;
            dfs(i,j);
            cnt++;
        }
    }
    cout<<cnt<<' ';
    memset(visit,false,sizeof(visit));
    cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]=='G')
                arr[i][j]='R';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(visit[i][j]) continue;
            dfs(i,j);
            cnt++;
        }
    }
    cout<<cnt<<' ';
    return 0;
}