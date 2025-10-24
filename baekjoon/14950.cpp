#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,t;
int p[10001];
int ans=0;
bool visit[10001];

vector<pair<int,int>> edge[10001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

int main()
{
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    for(pair<int,int> x:edge[1]){
        pq.push({x.second,x.first});
    }
    visit[1]=true;
    int calc=0;
    while (!pq.empty())
    {
        int cost=pq.top().first;
        int next=pq.top().second;
        pq.pop();
        if(visit[next])continue;
        visit[next]=true;
        for(pair<int,int> x:edge[next]){
            pq.push({x.second,x.first});
        }
        ans+=cost+calc;
        calc+=t;
    }
    cout<<ans;
    return 0;
}