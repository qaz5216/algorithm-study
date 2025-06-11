#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int distance[2001];
bool visit[2001];
bool flag=false;
int n,m;
vector<int> edge[2001];

void dfs(int cur,int dist)
{
    if(dist==4)
    {
        flag=true;
        return;
    }
    for(int next:edge[cur])
    {
        if(visit[next]) continue;
        visit[next]=true;
        dfs(next,dist+1);
        visit[next]=false;
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(flag) continue;
        memset(visit,false,sizeof(visit));
        visit[i]=true;
        dfs(i,0);
    }
    if(flag) cout<<1;
    else cout<<0;
    return 0;
}