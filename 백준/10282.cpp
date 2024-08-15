#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n,d,c;
        cin>>n>>d>>c;
        int dp[10001]={0};
        bool visit[10001]={false};
        vector<pair<int,int>> edge[10001];
        for(int i=0;i<d;i++)
        {
            int a,b,s;
            cin>>a>>b>>s;
            edge[b].push_back({s,a});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,c});
        while (!pq.empty())
        {
            pair<int,int> cur=pq.top();pq.pop();
            if(visit[cur.second]) continue;
            visit[cur.second]=true;
            dp[cur.second]=cur.first;
            for(pair<int,int> next:edge[cur.second])
            {
                pq.push({cur.first+next.first,next.second});
            }
        }
        int num=0;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            if(visit[i])num++;
            mx=max(mx,dp[i]);
        }
        cout<<num<<" "<<mx<<"\n";
    }
    return 0;
}