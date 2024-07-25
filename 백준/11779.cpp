#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
int dp[1001];
int p[1001];
vector <pair<int,int>> edge[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1e9;
    }
    int x,y;
    cin>>x>>y;
    dp[x]=0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,x});
    while (pq.empty()==0)
    {
        int cost=-pq.top().first;
        int cur=pq.top().second;
        pq.pop();
        if(cost>dp[cur]) continue;
        for(pair<int,int> next:edge[cur])
        {
            if(dp[next.first]>cost+next.second)
            {
                dp[next.first]=cost+next.second;
                pq.push({-dp[next.first],next.first});
                p[next.first]=cur;
            }
        }
    }
    
    cout<<dp[y]<<"\n";
    int tmp=y;
    vector<int> ans;
    while(tmp!=x)
    {
        ans.push_back(tmp);
        tmp=p[tmp];
    }
    ans.push_back(x);
    cout<<ans.size()<<"\n";
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}