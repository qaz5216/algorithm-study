#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int arr[1001][1001];
int dp[1001][1001];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(){
    int x,y;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];
            if(arr[i][j]==2)
            {x=i;y=j;}
        }
    }

    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        pair<int,int> now = q.front(); q.pop();
        for(int d = 0; d < 4; d++) {
            int nx = now.first + dx[d];
            int ny = now.second + dy[d];
            if(nx > 0 && nx <= n && ny > 0 && ny <= m) {
                if(arr[nx][ny]==1){
                    if(dp[nx][ny]==0){
                        dp[nx][ny]=dp[now.first][now.second]+1;
                        q.push({nx, ny});
                    }   
                    else if(dp[nx][ny]>dp[now.first][now.second]+1){
                        dp[nx][ny]=dp[now.first][now.second]+1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j]==0&&arr[i][j]==1)
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << dp[i][j]<<" ";
            }
            cout << "\n";
    }

    return 0;
}