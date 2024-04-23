#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MN 21

int N,M;
vector<int> g[MN*2];
vector<int> rg[MN*2];
vector<int> st;
bool visit[MN*2];
vector<vector <int>> ssc;
int ssclayer[MN*2];
int sscidx=0;
int ans[MN*2];

int notx(int x)
{
    return x>N?x-N:x+N;
}

void dfs(int n)
{
    visit[n]=true;
    for(int next:g[n])
    {
        if(visit[next]) continue;
        dfs(next);
    }
    st.push_back(n);
}
void redfs(int n)
{
    visit[n]=true;
    for(int next:rg[n])
    {
        if(visit[next]) continue;
        redfs(next);
    }
    ssclayer[n]=ssc.size();
    ssc.back().push_back(n);
}
int main()
{
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a<0) a=-a+N;
        if(b<0) b=-b+N;
        g[notx(a)].push_back(b);
        g[notx(b)].push_back(a);
        rg[b].push_back(notx(a));
        rg[a].push_back(notx(b));
    }
    for(int i=1;i<=N*2;i++)
    {
        if(visit[i]) continue;
        dfs(i);
    }
    memset(visit,false,sizeof(visit));
    reverse(st.begin(),st.end());
    for(int n:st)
    {
        if(visit[n]) continue;
        ssc.push_back(vector<int>());    
        redfs(n);
    }
    for(int i=1;i<=N;i++)
    {
        if(ssclayer[i]==ssclayer[i+N])
        {
            cout<<0;
            return 0;
        } 
    }
    cout<<1<<"\n";
    memset(visit,false,sizeof(visit));
    for(vector<int> ss:ssc)
    {
        for(int n:ss)
        {
            if(visit[n]) continue;
            visit[n]=true;
            visit[notx(n)]=true;
            ans[n]=0;
            ans[notx(n)]=1;
        }
    }
    for(int i=1;i<=N;i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}