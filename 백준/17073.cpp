#include <iostream>
#include <vector>
using namespace std;

int N;
double W;
double leaf=0;
vector<int> edge[500001];
bool visit[500001]={false};

void dfs(int cur)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cnt=0;
    for(int next:edge[cur])
    {
        if(!visit[next])
        {
            cnt++;
            visit[next]=true;
            dfs(next);
        }
    }
    if(cnt==0)
    {
        leaf+=1;
    }

    return;
}

int main()
{
    cin >> N >> W;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    visit[1]=true;
    dfs(1);
    cout.precision(10);
    cout<<W/leaf;
    return 0;
}