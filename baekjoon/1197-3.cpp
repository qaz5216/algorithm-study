#include <iostream>
#include <queue>

using namespace std;

int v,e,answer;
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
>pq;

int p[10001];

int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

int main()
{
    answer=0;
    cin>>v>>e;
    for(int i=1;i<=v;i++)p[i]=i;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    while(!pq.empty()){
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        int c=pq.top().first;
        pq.pop();
        a=find(a);
        b=find(b);
        if(a==b)continue;
        answer+=c;
        if(a>b)swap(a,b);
        p[b]=a;
    }
    cout<<answer;
    return 0;
}