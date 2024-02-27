#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n,m;
int map[1001][1001];
int dist[1001][1001];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1 ,0};
/* 완탐
void solve(int x,int y)
{
    if (map[x][y]==2)
    {
        dist[x][y]=0;
    }
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m){   //그래프 범위안
            if (dist[nx][ny]!=0)    //갈수있는 노드인가?
            {
                if(dist[nx][ny]==-1)    //방문한노드인가?
                {
                    dist[nx][ny]=dist[x][y]+1;
                    solve(nx,ny);
                }
                else if(dist[nx][ny]>dist[x][y]+1){ //방문했다면 내노드+1 보다 큰가?
                    dist[nx][ny]=dist[x][y]+1;
                    solve(nx,ny);
                }
            }
        }
        
    }
}
*/

void solve(int x,int y)
{   
    queue<pair<int,int>>q;
    q.push({x,y});
    while (!q.empty())
    {
        pair<int,int>now=q.front();q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=now.first+dx[i];
            int ny=now.second+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m){   //그래프 범위안
                if (map[nx][ny]==1)    //갈수있는 노드인가?
                {
                    if(dist[nx][ny]==-1)    //방문한노드인가?
                    {
                        dist[nx][ny]=dist[now.first][now.second]+1;
                        q.push({nx,ny});
                    }
                    else if(dist[nx][ny]>dist[now.first][now.second]+1){ //방문했다면 내노드+1 보다 큰가?
                        dist[nx][ny]=dist[now.first][now.second]+1;
                        q.push({nx,ny});
                    }
               }
            }
            //cout<<"now={"<<now.first<<","<<now.second<<"} next={"<<nx<<","<<ny<<"} dist="<<dist[nx][ny]<<endl;
        }   
    }
}


int main(){
    int tmp;
    int ax,ay;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tmp;
            if (tmp==2)
            {
                ax=i;ay=j;
            }
            if (tmp==0)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=-1;
            }
            map[i][j]=tmp;
            
        }
    }
    //solve
    dist[ax][ay]=0;
    solve(ax,ay);
    //ans
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}