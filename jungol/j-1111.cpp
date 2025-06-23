#include <iostream>
#include <queue>
using namespace std;

int ans=1000001;
int n;
int sx,sy;
int mount[102][102];
int cost[102][102];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int maxq=0;
queue<pair<int,int>> q;
int calc(pair<int,int> cur,pair<int,int>next)
{
    int temp = mount[next.first][next.second] - mount[cur.first][cur.second];
    if (temp < 0) temp = temp  * temp;
    return temp;
}
//0 or n+1 이면 종료
int main()
{
    cin>>n;
    cin>>sx>>sy;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mount[i][j];
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            cost[i][j]=1000001;
        }
    }
    cost[sx][sy]=0;
    q.push({sx,sy});
    while(!q.empty()){
        maxq=max(maxq,(int)q.size());
        pair<int,int> cur=q.front();q.pop();
        for(int i=0;i<4;i++){
            pair<int,int> next;
            next.first=cur.first+dx[i];
            next.second=cur.second+dy[i];
            int dist=calc(cur,next);
            if(cost[next.first][next.second]>cost[cur.first][cur.second]+dist)
            {
                cost[next.first][next.second]=cost[cur.first][cur.second]+dist;
                if(next.first<=0||next.first>=101||next.second<=0||next.second>=101) {
                    ans=min(ans,cost[next.first][next.second]);
                    continue;
                }
                q.push(next);
            }
        }
    }
    cout<<maxq;
    return 0;
}