#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int v,e;
int ans=1e9;
vector<pair<int,int>> edge[401];
bool visit[401];
int dist[401][401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>v>>e;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            dist[i][j]=1e9;
        }
    }
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            for(int k=1;k<=v;k++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        ans=min(ans,dist[i][i]);    
    }
    if(ans==1e9) cout<<-1;
    else cout<<ans;
    return 0;
}