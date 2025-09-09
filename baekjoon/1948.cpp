#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int>> edge[10001];
vector<pair<int,int>> r_edge[10001];
int dist[10001];
int degree[10001];
int n,m;
int st,en;
bool visit[10001];

queue<pair<int,int>> q;

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        edge[a].push_back({b,w});
        degree[b]++;
        r_edge[b].push_back({a,w});
    }
    cin>>st>>en;
    q.push({st,0});
    while(!q.empty()){
        int cur=q.front().first;
        int curdist=q.front().second;
        q.pop();
        //cout<<cur<<","<<curdist<<"=";
        for(pair<int,int> np:edge[cur]){
            int next=np.first;
            int ndist=np.second;
            //cout<<"("<<next<<','<<curdist+ndist<<")";
            dist[next]=max(dist[next],curdist+ndist);
            degree[next]--;
            if(degree[next]==0){
                q.push({next,dist[next]});
            }
        }
        //cout<<'\n';
    }
    queue<int> qq;
    int cnt=0;
    qq.push(en);
    visit[en]=true;
    while(!qq.empty()){
        int cur=qq.front();
        qq.pop();
        for(pair<int,int> pp:r_edge[cur]){
            int pre=pp.first;
            int pdist=pp.second;
            if(dist[cur]-pdist==dist[pre])
            {
                cnt++;
                if(visit[pre])continue;
                visit[pre]=true;
                qq.push(pre);
            }
        }
    }
    cout<<dist[en]<<'\n'<<cnt;
    return 0;
}
/*
진입차수 전부 보면서 최대거리 찾기
최대거리찾고 최대거리 추적
*/
