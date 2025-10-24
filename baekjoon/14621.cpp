#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,m;
bool man[1001];
vector<pair<int,pair<int,int>>> edges; 
priority_queue<pair<int,pair<int,int>>,
vector<pair<int,pair<int,int>>>,
greater<pair<int,pair<int,int>>>
> pq;
int p[1001];

int find(int x){
    if(x==p[x])return x;
    return p[x]=find(p[x]);
}

void my_union(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a>b)swap(a,b);
    p[b]=a;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='M'){
            man[i]=true;
        }
        p[i]=i;
    }
    for(int i=0;i<m;i++){
        int u,v,d;
        cin>>u>>v>>d;
        u=u-1;
        v=v-1;
        if(man[u]){
            if(man[v])continue;
        }
        else{
            if(!man[v])continue;
        }
        pq.push({d,{u,v}});
    }
    int ans=0;
    while(!pq.empty()){
        int a=pq.top().second.first;
        int b=pq.top().second.second;
        int d=pq.top().first;
        pq.pop();
        if(find(a)==find(b)) continue;
        my_union(a,b);
        ans+=d;
    }
    for(int i=0;i<n;i++){
        if(find(i)!=0){
            cout<<-1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}