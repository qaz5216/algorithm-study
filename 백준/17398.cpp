#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define ll long long

int N,M,Q;

int P[100001];
ll num[100001];
vector<pair<int,int>> edge;
vector<pair<int,int>> query;
bool exist[100001];
ll ans=0;

int find(int x)
{
    if(x==P[x])
        return x;
    return P[x]=find(P[x]);
}

ll myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return 0;
    if(a>b)swap(a,b);
    P[b]=P[a];
    ll cost=num[a]*num[b];
    num[a]+=num[b];
    num[b]=0;
    return cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>Q;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        edge.push_back({a,b});
    }
    memset(exist,true,sizeof(exist));
    for(int i=0;i<Q;i++)
    {
        int a;
        cin>>a;
        query.push_back(edge[a-1]);
        exist[a-1]=false;
    }
    for(int i=1;i<=N;i++)
    {
        P[i]=i;
        num[i]=1;
    }
    for(int i=0;i<M;i++)
    {
        if(exist[i])
        {
            myunion(edge[i].first,edge[i].second);
        }
    }
    //쿼리시작
    reverse(query.begin(),query.end());
    for(pair<int,int> e:query)
    {
        ans+=myunion(e.first,e.second);
    }
    cout<<ans;
    return 0;
}