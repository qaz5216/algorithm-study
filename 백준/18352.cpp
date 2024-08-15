#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dist[300001];
vector<int> edge[300001];

int main()
{
    memset(dist,-1,sizeof(dist));
    vector<int> answer;
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
    }
    queue<pair<int,int>> pq;
    pq.push({0,x});
    dist[x]=0;
    while(!pq.empty())
    {
        pair<int,int> cur=pq.front(); pq.pop();
        for(int next:edge[cur.second])
        {
            if(dist[next]==-1)
            {
                dist[next]=cur.first+1;
                pq.push({cur.first+1,next});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==k)
            answer.push_back(i);
    }
    if(answer.size()==0)
    {
        cout<<-1;
    }
    else
    {
        for(int node:answer)
        {
            cout<<node<<"\n";
        }
    }
    return 0;
}