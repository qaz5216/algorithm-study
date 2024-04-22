#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
vector<int> g[32001];
vector<int> st;
int in_degree[32001];

int main()
{  
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        in_degree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=N;i++)
    {
        if(in_degree[i]==0)
        {
            visit[i]=true;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int cur=q.front();q.pop();
        st.push_back(cur);
        for(int nxt:g[cur])
        {
            if(--in_degree[nxt]==0) q.push(nxt);
        }
    }
    for(int cur:st)
    {
        cout<<cur<<" ";
    }
    return 0;
}