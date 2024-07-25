#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int dist[101][101];
int p[101][101];

vector<int> getroute(int s,int e)
{
    if(p[s][e]==s) return {s,e};
    vector<int> v;
    vector<int> l = getroute(s,p[s][e]);
    vector<int> r = getroute(p[s][e],e);
    for(int x:l) v.push_back(x);
    v.pop_back();
    for(int x:r) v.push_back(x);
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=1e9;
            if(i==j) dist[i][j]=0;
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(c<dist[a][b]){
        p[a][b]=a;
        dist[a][b]=c;
        }
    }

    for(int m=1;m<=n;m++)
    {
        for(int s=1;s<=n;s++)
        {
            for(int e=1;e<=n;e++)
            {
                if(s==e) continue;
                if(dist[s][e]>dist[s][m]+dist[m][e])
                {
                    dist[s][e]=dist[s][m]+dist[m][e];
                    p[s][e]=m;
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==1e9)cout<<0<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j||dist[i][j]==1e9)
            {
                cout<<0<<"\n";
            }
            else
            {
                vector<int> v=getroute(i,j);
                cout<<v.size()<<" ";
                for(int x:v) cout<<x<<" ";
                cout<<"\n";
            }
        }
    }
    return 0;
}