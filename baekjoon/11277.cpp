#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define MN 10001

int N,M;
vector<int> g[MN*2];
vector<int> rg[MN*2];
vector<int> st;
bool visit[MN*2];
vector<vector<int>>ssc;
int ssclayer[MN*2];

int notx(int x)
{
    return x>N ? x-N:x+N;
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

void rdfs(int n)
{
    visit[n]=true;
    for(int next:rg[n])
    {
        if(visit[next]) continue;
        rdfs(next);
    }
    ssc.back().push_back(n);
    ssclayer[n]=ssc.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a<0)a=-a+N;
        if(b<0)b=-b+N;
        g[notx(a)].push_back(b);
        g[notx(b)].push_back(a);
        rg[b].push_back(notx(a));
        rg[a].push_back(notx(b));
    }
    for(int i=1;i<=2*N;i++)
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
        rdfs(n);
    }
    for(int i=1;i<=N;i++)
    {
        if(ssclayer[i]==ssclayer[i+N])
        {
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}