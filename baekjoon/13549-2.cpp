#include <iostream>
#include <queue>
using namespace std;

int n,k;
int dp[100001];
bool visit[100001];
priority_queue< pair<int,int> ,
vector<pair<int,int>> ,
greater<pair<int,int>>> q;
int main()
{
    cin>>n>>k;
    for(int i=0;i<100001;i++){
        dp[i]=-1;
    }
    q.push({0,n});
    int cnt=0;
    while (!q.empty())
    {
        int num=q.top().first;
        int cur=q.top().second;
        q.pop();
        if(cur==k){
            cout<<num;
            break;
        }
        if(dp[cur]!=-1&&dp[cur]<=num) continue;
        dp[cur]=num;
        int next=cur*2;
        while(next<100001&&next!=0){
            if(visit[next]) break;
            visit[next]=true;
            q.push({num,next});
            next*=2;
        }
        if(cur+1<100001)
            q.push({num+1,cur+1});
        if(cur-1>=0)
            q.push({num+1,cur-1});
    }
    
    return 0;
}