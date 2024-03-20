#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> edge[10001];
int ans=0;
int dist[10001];

void dfs(int x)
{
    if(edge[x].size()==0)
    {   //리프노드
        dist[x]=0;
    }
    else if(edge[x].size()==1)
    {
        for(int i=0;i<edge[x].size();i++)
        {
            dfs(edge[x][i].first);
            dist[x]=max(dist[x],dist[edge[x][i].first]+edge[x][i].second);
            ans=max(ans,dist[x]);
        }
    }
    else
    {
        int prei=1;
        int maxi=0;
        dfs(edge[x][0].first);
        dist[x]=max(dist[x],dist[edge[x][0].first]+edge[x][0].second);
        
        dfs(edge[x][1].first);
        dist[x]=max(dist[x],dist[edge[x][1].first]+edge[x][1].second);
        if(dist[edge[x][0].first]+edge[x][0].second<=dist[edge[x][1].first]+edge[x][1].second)
        {
            maxi=1;
            prei=0;
        }
        for(int i=2;i<edge[x].size();i++)
        {
            dfs(edge[x][i].first);
            dist[x]=max(dist[x],dist[edge[x][i].first]+edge[x][i].second);
            //cout<<i<<": dist="<<dist[edge[x][i].first]+edge[x][i].second<<"\n";
            if(dist[edge[x][maxi].first]+edge[x][maxi].second<=dist[edge[x][i].first]+edge[x][i].second)//지금까지중 가장 긴라인이면
            {
                prei=maxi;
                maxi=i;
            }
            else if(dist[edge[x][prei].first]+edge[x][prei].second<=dist[edge[x][i].first]+edge[x][i].second)
            {
                prei=i;
            }
        }
        int l=dist[edge[x][maxi].first]+edge[x][maxi].second;
        int r=dist[edge[x][prei].first]+edge[x][prei].second;
        ans=max(ans,dist[x]);
        ans=max(ans,l+r);
        //cout<<x<<": ans="<<ans<<" l="<<l<<"r="<<r<<"\n";
    }
    return ;
}

int main()
{
    cin >> N;
    for(int i=1;i<N+1;i++)
    {
        dist[i]=0;
    }
    for(int i=0;i<N-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    dfs(1);
    cout<<ans;
    return 0;
}


/*
다른풀이
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> edge[10001];
int ans=0;
int maxi=0;
bool visit[10001]={false};
void dfs(int x,int val)
{
    visit[x]=true;
    if(val>ans)
    {
        ans=val;
        maxi=x;
    }
    for(pair<int,int> e:edge[x])
    {
        if(!visit[e.first])
        {
            dfs(e.first,val+e.second);
        }
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    dfs(1,0);
    for(int i=1;i<N+1;i++)
    {
        visit[i]=false;
    }
    dfs(maxi,0);
    cout<<ans;
    return 0;
}
*/