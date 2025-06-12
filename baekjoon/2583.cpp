#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m,n,k;
bool arr[101][101];
bool visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<int> ans;
int tmp=0;
void my_fill(int lx,int rx,int ly,int ry){
    for(int i=lx;i<rx;i++)
    {
        for(int j=ly;j<ry;j++)
        {
            arr[i][j]=1;
        }
    }
}

void dfs(int x,int y)
{
    visit[x][y]=true;
    tmp++;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)
        {
            if(!arr[nx][ny]&&!visit[nx][ny])
            {
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    cin>>m>>n>>k;
    for(int i=0;i<k;i++)
    {
        int lx,rx,ly,ry;
        cin>>lx>>ly>>rx>>ry;
        my_fill(lx,rx,ly,ry);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]||visit[i][j])continue;
            tmp=0;
            dfs(i,j);
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(int answer:ans)
        cout<<answer<<' ';
    return 0;
}