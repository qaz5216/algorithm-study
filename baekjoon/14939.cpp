#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 1e9;
int n,m,r;
int area[101];
vector<pair<int,int>>edge[101];
int tem[101];
int dist[101];
void dijkstra(int x)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
    }
    dist[x]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,x});
    while(!pq.empty())
    {
        pair<int,int> now=pq.top();pq.pop();
        for(pair<int,int> next:edge[now.second])
        {
           if(dist[next.second]>now.first+next.first)
            {
                dist[next.second]=now.first+next.first;
                pq.push({now.first+next.first,next.second});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<=m)
            tem[x]+=area[i];    
    }
    
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        dijkstra(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,tem[i]);
    }
    cout<<ans;
}

int main()
{
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        area[i]=num;
    }
    for(int i=0;i<r;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }
    solve();
    
    return 0;
}