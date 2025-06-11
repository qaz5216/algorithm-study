#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
int n;
const int MN = 101;
bool visit[MN][MN];
int arr[MN][MN];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x,int y, int h){
    for(int d=0;d<4;d++){
        int xx=x+dx[d];
        int yy=y+dy[d];
        if(xx>0&&yy>0&&xx<=n&&yy<=n){
            if(visit[xx][yy]||arr[xx][yy]<=h)
                continue;
            visit[xx][yy]=true;
            dfs(xx,yy,h);
        }    
    }
}

int main() {
    int mh=0,cnt,ans;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
            mh=max(mh,arr[i][j]);
        }
    }
    ans=0;
    for(int h=0;h<mh;h++){
        memset(visit,0,sizeof(visit));
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]-h<=0||visit[i][j])
                continue;
                visit[i][j]=true;
                cnt++;
                dfs(i,j,h);
            }
        }
        ans=max(ans,cnt);
    }
    cout <<ans<< '\n';
}