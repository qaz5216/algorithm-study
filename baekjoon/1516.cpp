#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[501];
vector<int> g[501];
int fin[501];
vector<int> st;
bool visit[501];

void dfs(int cur)
{
    visit[cur]=true;
    for(int next:g[cur])
    {
        if(visit[next])continue;
        dfs(next);
    }
    st.push_back(cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
        while(true)
        {
            int a;
            cin >> a;
            if(a==-1)
            {
                break;
            }
            g[i].push_back(a);
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(visit[i]) continue;
        dfs(i);
    }
    for(int cur:st)
    {
        fin[cur]+=arr[cur];
        for(int nxt:g[cur])
        {
            fin[cur]=max(fin[cur],fin[nxt]+arr[cur]);
        }
    }
    for(int i=1;i<=N;i++)
    {
        cout<<fin[i]<<"\n";
    }
    return 0;
}