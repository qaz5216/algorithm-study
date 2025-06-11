#include <iostream>
#include <queue>

using namespace std;

int n,m;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
int p[100001];

int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}

bool isunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return true;
    return false;
}

void my_union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a>b)swap(a,b);
    p[b]=a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        pq.push({c,{a,b}});
    }
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    int ans=0;
    int tmp=0;
    while (!pq.empty())
    {
        pair<int,pair<int,int>> cur=pq.top();pq.pop();
        if(!isunion(cur.second.first,cur.second.second))
        {
            my_union(cur.second.first,cur.second.second);
            ans+=cur.first;
            tmp=cur.first;
        }
    }
    cout<<ans-tmp;
    return 0;
}