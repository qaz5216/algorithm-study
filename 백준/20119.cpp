#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N,M;
vector <vector<int>> resp[200001];
vector <int> edge[200001];
vector <int> arr;
vector <int> ans;
vector <int> st;
bool visit[200001];
bool can[200001];

void dfs(int x)
{
    visit[x]=true;
    for(int next:edge[x])
    {
        if(visit[next]) continue;
        dfs(next);
    }
    st.push_back(x);
}

void dfs2(int x)
{
    visit[x]=true;
    for(int next:edge[x])
    {
        if(visit[next]) continue;
        else{
            if(can[next])
            {
                dfs2(next);
            }
            else
            {
                //만들순있고?
                if(resp[next].size()==0) continue;
                bool canmake=false;
                for(vector<int> vec:resp[next])
                {
                    bool flag=true;
                    if(vec.size()==0) continue;
                    for(int x:vec)
                    {
                        if(!can[x])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if(flag)
                    {
                        canmake=true;
                        break;
                    }
                }
                if(canmake)
                {
                    can[next]=true;
                    dfs2(next);
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<M;i++)
    {
        int k;
        cin>>k;
        vector<int> tmp;
        for(int j=0;j<k;j++)
        {
            int a;
            cin>>a;
            tmp.push_back(a);
        }
        int r;
        cin >> r;
        resp[r].push_back(vector<int>());
        for(int a:tmp)
        {
            resp[r].back().push_back(a);
            edge[a].push_back(r);
        }
    }
    int L;
    cin>>L;
    for(int i=0;i<L;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
        can[a]=true;
    }
    for(int i=1;i<=N;i++)
    {
        if(visit[i]) continue;
        dfs(i);
    }
    for(int i=1;i<=N;i++)
    {
        visit[i]=false;
    }
    reverse(st.begin(),st.end());
    
    for(int e:st)
    {
        if(visit[e]) continue;
        if(can[e])
        {
            dfs2(e);
        }
    }

    for(int i=1;i<=N;i++)
    {
        if(can[i])
        {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<"\n";
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}