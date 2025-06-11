/*

sol 1;

#include <iostream>

using namespace std;
int n;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool map[102][102];

int main()
{
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        for(int x=a+1;x<a+11;x++){
            for(int y=b+1;y<b+11;y++){
                map[x][y]=true;
            }
        }
    }
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++)
        {
            if(map[i][j]){
                for(int k=0;k<4;k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(!map[nx][ny]) {ans++;}
                }
            }            
        }
    }
    cout<<ans;
    return 0;
}

*/

//sol 2

#include <iostream>
#include <vector>

using namespace std;
int n;
vector <pair<int,int>> v;
bool map[102][102];
//visit 배열분리 4개로
bool visit[4][102][102];

int main()
{
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a+1,b+1});
        for(int x=a+1;x<a+11;x++){
            for(int y=b+1;y<b+11;y++){
                map[x][y]=true;
            }
        }
    }
    for(pair<int,int> p:v)
    {
        int x=p.first;
        int y=p.second;
        for(int i=x;i<x+10;i++)//윗변
        {
            if(!map[i][y+10]&&!visit[0][i][y+9]){visit[0][i][y+9]=true;ans++;}
        }for(int i=x;i<x+10;i++)//아랫변
        {
            if(!map[i][y-1]&&!visit[1][i][y]){visit[1][i][y]=true;ans++;}
        }for(int i=y;i<y+10;i++)//왼쪽변
        {
            if(!map[x+10][i]&&!visit[2][x+9][i]){visit[2][x+9][i]=true;ans++;}
        }for(int i=y;i<y+10;i++)//오른족변
        {
            if(!map[x-1][i]&&!visit[3][x][i]){visit[3][x][i]=true;ans++;}
        }
    }
    cout<<ans;
    return 0;
}