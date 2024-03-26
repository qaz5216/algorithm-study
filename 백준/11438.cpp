#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N,M;
vector <int> edge[100001];
vector <int> ans;
int fedge[100001];
bool visit[100001];

void dfs(int x)
{
    visit[x]=true;
    for(int next:edge[x])
    {
        if(!visit[next])
        {
            fedge[next]=x;
            dfs(next);
        }
    }
}

int main()
{
    cin>>N;
    for(int i=1;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(visit,false,sizeof(visit));
    fedge[1]=1;
    dfs(1);
    
    cin>>M;
    while(M--)
    {
        int a,b;
        cin >> a>>b;
        queue<int> q;
        q.push(a);
        q.push(b);
        memset(visit,false,sizeof(visit));
        while(!q.empty())
        {   
            int cur=q.front();q.pop();
            if(visit[cur])
            {
                ans.push_back(cur);
                break;
            }
            visit[cur]=true;
            q.push(fedge[cur]);
        }
    }
    for(int answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}