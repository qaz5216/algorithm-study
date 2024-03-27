#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

vector<pair<int,pair<int,int>>> edge;
int N;
int P[100001];
int NUM[100001];
ll ans=0;
int find(int x)
{
    if(x==P[x])
    {
        return x;
    }
    return P[x]=find(P[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
    return;
    if(a>b)swap(a,b);
    
    NUM[a]+=NUM[b];
    NUM[b]=0;
    P[b]=P[a];
}

int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        P[i]=i;
        NUM[i]=1;
    }
    for(int i=1;i<N;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }
    sort(edge.begin(),edge.end());
    reverse(edge.begin(),edge.end());
    for(pair<int,pair<int,int>> e:edge)
    {
        int a=find(e.second.first);
        int b=find(e.second.second);
        ans+=((ll)NUM[a]*(ll)NUM[b]*(ll)e.first);
        myunion(a,b);
    }
    cout<<ans;
    
    return 0;
}
//유니온파인드로 하나씩 연결하기