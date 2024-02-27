#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321;

int N,E;
int v1,v2;
vector<pair<int,int>> edge[801];
int dist[801];
int distv1[801];
int distv2[801];
//1 v1->v2->N vs v2->v1->N
/*
    1번에서 다익스트라
    v1에서 
    v2에서 
    하고 더하고 비교?
    다익스트라 *3
*/

void dijkstra(int x)
{
    priority_queue<pair<int,int>> pq;
    pq.push({0,x});
    dist[x]=0;
    while(!pq.empty())
    {
        pair<int,int> now=pq.top();pq.pop();
        for(pair<int,int>next:edge[now.second])
        {
            if(dist[next.second]>next.first+now.first)
            {
                dist[next.second]=next.first+now.first;
                pq.push({next.first+now.first,next.second});
            }
        }
    }
}

void solve()
{
    for(int i=1;i<=N;i++)
        dist[i]=INF;
    dijkstra(v1);
    for(int i=1;i<=N;i++){
        distv1[i]=dist[i];
        dist[i]=INF;
    }
    dijkstra(v2);
    for(int i=1;i<=N;i++){
        distv2[i]=dist[i];
        dist[i]=INF;
    }
    dijkstra(1);
    //v1-v2-N
    int ans1=INF;
    if(dist[v1]<987654321&&distv1[v2]<987654321&&distv2[N]<987654321)
    ans1=dist[v1]+distv1[v2]+distv2[N];
    //v2-v1-N
    int ans2=INF;
    if(dist[v2]<987654321&&distv2[v1]<987654321&&distv1[N]<987654321)
    ans2=dist[v2]+distv2[v1]+distv1[N];
    int ans=min(ans1,ans2);
    //cout<<"ans1 = "<<ans1<<" ans2 = "<<ans2;
    if(ans<987654321)
    cout<<ans;
    else
    cout<<"-1";
}

int main()
{
    cin>>N>>E;
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }
    cin>>v1>>v2;
    //solve
    solve();


    return 0;
}