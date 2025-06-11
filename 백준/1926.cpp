#include <iostream>

using namespace std;

int n,m;
int ans=0,tmp=0;
int cnt=0;
bool arr[501][501];
bool visit[501][501];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


void dfs(int x,int y)
{
    visit[x][y]=true;
    tmp++;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)
            if(arr[nx][ny]&&!visit[nx][ny])
            {
                dfs(nx,ny);
            }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!arr[i][j]||visit[i][j])continue;
            cnt++;
            tmp=0;
            dfs(i,j);
            ans=max(ans,tmp);
        }
    }
    cout<<cnt<<"\n";
    cout<<ans;
    return 0;
}