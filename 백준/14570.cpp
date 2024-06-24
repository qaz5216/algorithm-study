#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int edge[200001][2];
ll tree[200001];
ll N,K;
int ans;
vector<int> dp;

void dfs(int cur,ll x)
{
    if(edge[cur][0]==-1&&edge[cur][1]==-1){//단말도착
        ans=cur;
    }
    else if(edge[cur][0]==-1){
        dfs(edge[cur][1],x);
    }
    else if(edge[cur][1]==-1){
        dfs(edge[cur][0],x);
    }
    else{   //자식 두개다있을때
        if(x%2==1)//홀수면 왼쪽
        {
            dfs(edge[cur][0],x/2+1);
        }
        else
        {
            dfs(edge[cur][1],x/2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int a,b;
        cin>>edge[i][0]>>edge[i][1];
    }
    cin>>K;
    dfs(1,K);
    cout<<ans;
    return 0;
}