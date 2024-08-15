#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,t;
        cin>>n>>m>>t;
        int s,g,h;
        cin>>s>>g>>h;
        vector<pair<int,int>> edge[2001];
        for(int i=0;i<m;i++)
        {
            int a,b,d;
            cin>>a>>b>>d;
            edge[a].push_back({b,d});
            edge[b].push_back({a,d});
        }
        vector<int> sub;
        for(int i=0;i<t;i++)
        {
            int x;
            cin>>x;
            sub.push_back(x);
        }
        bool visit[2001]={false};
        bool check[2001]={false};
        //{지난거리{현재위치,교차로지났는지(0,1)}}
        priority_queue< pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{s,0}});
        int dp[2001]={0};
        while(!pq.empty())
        {
            pair<int,pair<int,int>> cur=pq.top(); pq.pop();
            if(visit[cur.second.first])
            {
                if(dp[cur.second.first]==cur.first&&cur.second.second&&!check[cur.second.first]){}
                else continue;
            }
            visit[cur.second.first]=true;
            dp[cur.second.first]=cur.first;
            check[cur.second.first]=cur.second.second;
            for(pair<int,int> next:edge[cur.second.first])
            {
                if(next.first==g&&cur.second.first==h)//특정도로 건너는경우
                {
                    pq.push({cur.first+next.second,{next.first,1}});
                }
                else if(next.first==h&&cur.second.first==g)//특정도로 건너는경우
                {
                    pq.push({cur.first+next.second,{next.first,1}});
                }
                else //특정도로아닌 경우
                {
                    pq.push({cur.first+next.second,{next.first,cur.second.second}});
                }
            }
        }
        vector <int> answer;
        for(int node:sub)
        {
            if(check[node])answer.push_back(node);
        }
        sort(answer.begin(),answer.end(),less<int>());
        for(int node:answer)
        {
            cout<<node<<" ";
        }
        
    }
    return 0;
}