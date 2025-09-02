#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int MN = 1001;
vector<int> edge[MN];
vector<int> st;
int arr[MN];
int fin[MN];
bool visit[MN];

void dfs(int cur){
    visit[cur]=true;
    for(int next:edge[cur]){
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
    int T;
    cin >> T;
    while (T--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

       for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            edge[b].push_back(a);
        }
        int w;
        cin>>w;
        dfs(w);
        for(int e:st){
            fin[e]+=arr[e];
            for(int next:edge[e]){
                fin[e]=max(fin[e],fin[next]+arr[e]);
            }
        }
        cout<<fin[w]<<'\n';
        for(int i=1;i<=n;i++){
            edge[i].clear();
            visit[i]=0;
            fin[i]=0;
            arr[i]=0;
        }
        st.clear();
    }
}