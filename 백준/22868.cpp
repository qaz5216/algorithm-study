#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> edge[10001];
bool visit[10001];
int n,m,ans=0;
int p[10001];
void dijkstra(int s,int e)
{
    queue<pair<int,int>> q;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    visit[s]=true;
    q.push({0,s});
    while(!q.empty())
    {
        int cur=q.front().second;
        int cost=q.front().first;
        q.pop();
        for(int next:edge[cur])
        {
            if(visit[next]) continue;
            p[next]=cur;
            visit[next]=true;
            if(next==e){
                ans+=cost+1;
                return;
            }
            q.push({cost+1,next});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        sort(edge[i].begin(),edge[i].end());
    }
    int s,e;
    cin>>s>>e;
    dijkstra(s,e);
    memset(visit,false,sizeof(visit));
    int path=e;
    while(path!=s)
    {
        path=p[path];
        visit[path]=true;
    }
    visit[s]=false;
    dijkstra(e,s);
    cout<<ans;
    return 0;
}