#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int V,E;
vector <int> g[10001];
vector <vector<int>> SCC;
vector <int> rg[10001];
vector <int> st;
bool visit[10001];

void dfs(int n)
{
    for(int next:g[n])
    {
        if(visit[next]) continue;
        visit[next] = true;
        dfs(next);
    }
    st.push_back(n);   
}

void dfs2(int n)
{
    for(int next:rg[n])
    {
        if(visit[next]) continue;
        visit[next] = true;
        dfs2(next);
    }
    SCC.back().push_back(n);   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }
    for(int i=1;i<=V;i++)
    {
        if(visit[i]) continue;
        visit[i]=true;
        dfs(i);
    }
    reverse(st.begin(),st.end());
    memset(visit,false,sizeof(visit));
    for(int n:st){
        if(visit[n]) continue;
        visit[n]=true;
        SCC.push_back(vector<int> ());
        dfs2(n);
    }
    // for(vector<int> &vec:SCC)
    // {
    //     sort(vec.begin(),vec.end());
    // }
    // sort(SCC.begin(),SCC.end());
    cout<<SCC.size()<<"\n";
    for(vector<int> vec:SCC)
    {
        for(int n:vec){
            cout<<n<<" ";
        }
        cout<<"-1\n";
    }
    return 0;
}