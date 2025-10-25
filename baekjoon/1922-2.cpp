#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<pair<int,int>> edge[1001];
bool visit[1001];
int sum=0;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }
    q.push({0,1});
    while (!q.empty())
    {
        int cost=q.top().first;
        int cur=q.top().second;
        q.pop();
        cout<<cur<<cost<<'\n';
        if(visit[cur])continue;
        sum+=cost;
        visit[cur]=true;
        for(pair<int,int>np:edge[cur])
        {
            if(!visit[np.first])
            q.push({np.second,np.first});
        }
    }
    cout<<sum;
    return 0;
}