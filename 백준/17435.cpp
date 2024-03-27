#include <iostream>
#include <vector>
using namespace std;

int M,Q;
int f[200001];
int dp[200001][20];
vector<pair<int,int>> q;
vector<int> ans;

int find(int n,int x)//f1(1)
{
    for(int i=0;i<20;i++)
    {
        if(n%2==1)
            x=dp[x][i];
        n/=2;
    }
    return x;
}

int main()
{
    cin>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>f[i];
    }
    cin>>Q;
    for(int i=0;i<Q;i++)
    {
        int a,b;
        cin>> a>>b;
        q.push_back({a,b});
    }
    for(int i=1;i<=M;i++)
    {
        dp[i][0]=f[i];
    }
    for(int i=1;i<20;i++)
    {
        for(int j=1;j<=M;j++)
        {
            dp[j][i]=dp[dp[j][i-1]][i-1];
        }
    }
    for(int i=0;i<Q;i++)
    {
        ans.push_back(find(q[i].first,q[i].second));
    }
    for(int answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}