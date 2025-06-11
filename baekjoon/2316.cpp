#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N,P;
vector<int> edge[801];
int c[801][801];
int d[801];
int max_flow(int s,int e)
{
    int cnt=0;
    while(true)
    {
        memset(d,-1,sizeof(d));
        d[s]=s;
        queue <int> q;
        q.push(s);
        while (!q.empty())
        {
            int cur=q.front();q.pop();
            for(int next:edge[cur])
            {
                if(c[cur][next]>0&&d[next]==-1){
                    q.push(next);
                    d[next]=cur;
                }
            }
        }
        if(d[e]==-1)
            break;
        for(int i=e;i!=s;i=d[i])
        {
            c[d[i]][i]-=1;
            c[i][d[i]]+=1;
        }
        cnt++;
    }
    return cnt;
}

int main()
{
    cin>>N>>P;
    for(int i=1;i<=N;i++)
    {
        edge[i].push_back(i+400);
        edge[i+400].push_back(i);
        c[i][i+400]+=1;
    }
    for(int i=0;i<P;i++)
    {
        int a,b;
        cin>>a>>b;
        edge[a+400].push_back(b);
        edge[b+400].push_back(a);
        edge[a].push_back(b+400);
        edge[b].push_back(a+400);
        c[a+400][b]+=1;
        c[b+400][a]+=1;
    }
    cout<<max_flow(401,2);
    return 0;
}