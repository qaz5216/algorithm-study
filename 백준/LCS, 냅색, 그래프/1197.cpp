#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 1e9;
int V,E;
vector<pair<int,pair<int,int>>> edge;
bool visit[10001];
int p[10001];

int find(int x)
{
    if(x==p[x]) return x;
    else
    return find(p[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    {return;}
    else{
        if(a>b)
            p[a]=b;
        else
            p[b]=a;
    }
}

int main()
{
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=V;i++)
    {
        p[i]=i;
    }
    int ans=0;
    for(int i=0;i<E;i++)
    {
        if(find(edge[i].second.first)!=find(edge[i].second.second))
        {
            
            cout<<edge[i].second.first<<" & "<<edge[i].second.second <<"parent"<<find(edge[i].second.first)<<" & "<<find(edge[i].second.second)<<endl;
            myunion(edge[i].second.first,edge[i].second.second);
            ans+=edge[i].first;
            cout<<"ans="<<ans<<endl;
        }
    }
    cout<< ans;
    return 0;
}