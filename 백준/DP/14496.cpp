#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int visit[1001];

int main()
{
    int a,b;
    int n,m;
    cin>> a>>b;
    cin>> n>>m;
    vector<int> edge[1001];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    memset(visit,-1,sizeof(visit));
    queue <int> q;
    q.push(a);
    visit[a]=0;
    while (!q.empty())
    {
        int now=q.front();q.pop();
        //cout<<"now = "<<now;
        if(now==b)
        {
            break;
        }
        for(int next:edge[now])
        {   
            //cout<<" next = "<<next;
            if(visit[next]==-1)
            {
                visit[next]=visit[now]+1;
                //cout<<" go -> visit["<<next<<"] = "<<visit[now]+1;
                q.push(next);
            }
        }
        //cout<<endl;
    }
    cout<<visit[b];

    return 0;
}