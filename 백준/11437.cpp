#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector <int> edge[50001];
vector <pair<int,int>> Q;
int height[50001];
int dp[50001][17];
vector <int> ans;

void dfs(int cur,int prev)
{
    for(int next:edge[cur])
    {
        if(prev==next)
            continue;
        height[next]=height[cur]+1;
        dp[next][0]=cur;
        dfs(next,cur);
    }
}

int LCA(int a,int b)
{
    if(height[a]<height[b]) swap(a,b);
    int gap=height[a]-height[b];
    for(int i=0;i<17;i++)//gap줄이기
    {
        if(gap%2==1)    
        {   
            a=dp[a][i]; 
        }
        gap/=2;
    }
    if(a==b)
        return a;
    for(int i=16;i>=0;i--)
    {
        if(dp[a][i]!=dp[b][i])
        {
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}

int main()
{
    cin >>N;
    for(int i=1;i<N;i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin >> a >> b;
        Q.push_back({a,b});
    }
    dfs(1,0);
    for(int i=1;i<17;i++){
        for(int j=1;j<=N;j++){
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    for(int i=0;i<M;i++)
    {
        int a=Q[i].first;
        int b=Q[i].second;
        ans.push_back(LCA(a,b));
    }

    for(int answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}