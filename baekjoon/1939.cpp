#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int dist[100001];
vector<pair<int,int>> edge[100001];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    int st,en;
    priority_queue<
    pair<int,int>
    >pq;
    cin>>st>>en;
    pq.push({1e9,st});
    while(!pq.empty()){
        int cur=pq.top().second;
        int cut=pq.top().first;
        pq.pop();
        if(dist[cur]>=cut)continue;
        dist[cur]=cut;
        for(pair<int,int> p:edge[cur]){
            int next=p.first;
            int nextcut=min(cut,p.second);
            if(dist[next]>=nextcut)continue;
            pq.push({nextcut,next});
        }
    }
    cout<<dist[en];
    return 0;
}