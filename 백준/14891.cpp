#include <iostream>

using namespace std;

bool arr[4][8];
int tmp[4];
int idx[4];
int dx[2]={1,-1};
bool visit[4];

int pow(int x,int r)
{
    if(r==0) return 1;
    if(r==1) return x;
    return x*pow(x,r-1);
}

int getidx(int x)
{
    if(x<0) x=8-abs(x%8);
    x=x%8;
    return x;
}

void dfs(int x,int dir)
{
    idx[x]+=dir;
    for(int i=0;i<2;i++)
    {
        int nx=x+dx[i];
        if(0<=nx&&nx<4){
            if(!visit[nx])
            {
                int xidx=getidx(2+tmp[x]);
                int nxidx=getidx(6+tmp[nx]);
                if(nx<x){//다음이 x보다 작은곳일때
                    xidx=getidx(6+tmp[x]);
                    nxidx=getidx(2+tmp[nx]);
                }
                if(arr[x][xidx]!=arr[nx][nxidx])
                {   //다르면
                    visit[nx]=true;
                    dfs(nx,-dir);
                }
                else//같으면
                {
                    visit[nx]=true;
                    dfs(nx,0);
                }
            }
        }
    }
}

int main()
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<8;j++)
        {
            char c;
            cin>>c;
            arr[i][j]=c-'0';
        }
    }
    int k;
    cin>>k;
    while(k--)
    {   //입력된 방향은 1이 시계 -1이 반시계
        //계산할때 방향은 1이 반시계 1이 시계방향임을 주의!
        int x,dir;
        cin>>x>>dir;
        x-=1;
        for(int i=0;i<4;i++) {visit[i]=false;tmp[i]=idx[i];}
        visit[x]=true;
        dfs(x,-dir);
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
        if(arr[i][getidx(idx[i])])
        {
            ans+=pow(2,i);
        }
    }
    cout<<ans;
    return 0;
}