#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;
#define INF 1e9;

int N;
int M;
int X;
vector<pair<int,int>> edge[2][1001];
int dist[1001];
int arr[1001];
int ans=0;

void print()
{  
    for(int i=1;i<=N;i++)
    {
        ans=max(ans,arr[i]);
    }
    cout << ans;
}

void solve()
{   //초기화
    for(int i=1;i<=N;i++)
    {
        arr[i]=0;
    }
    //dijkstra
    for(int i=0;i<=1;i++)
    {
        for(int j=1;j<=N;j++)
        {
        dist[j]=INF;
        }
        priority_queue <pair<int,int>> pq;
        pq.push({0,X});
        dist[X]=0;
        while(!pq.empty())
        {
            pair<int,int> now=pq.top(); pq.pop();
          
            for(pair<int,int> next:edge[i][now.second])
            {
                if(dist[next.second]>now.first+next.first)
                {
                    dist[next.second]=now.first+next.first;
                    pq.push({now.first+next.first,next.second});
                }
            }
        }
        for(int j=1;j<=N;j++)
        {
        arr[j]+=dist[j];
        }
    }
}

int main()
{
    cin >>N>>M>>X;
    for(int i=0;i<M;i++)
    {  
        int a,b,c;
        cin>>a>>b>>c;
        edge[0][a].push_back({c,b});
        edge[1][b].push_back({c,a});
    }
    //solve
    solve();
    //print
    print();
    return 0;
}