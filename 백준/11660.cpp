#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int N,M;
ll dp[1025][1025];
vector<ll> ans;
int main()
{
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>dp[i][j];
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c,d;
        cin >> a>>b>>c>>d;

        ll A=0,B=0,C=0;
        if(a!=0&&b!=0)
        {
            C=dp[a-1][b-1];
        }
        if(a!=0)
        A=dp[a-1][d];
        if(b!=0)
        B=dp[c][b-1];
        ll tmp=dp[c][d]-(A+B-C);
        ans.push_back(tmp);
    }
    for(ll answer:ans)
    {
        cout <<answer<<"\n";
    }
    return 0;
}

/*
1   2   3   4
2   4   6   8
3   6   9   12
4   8   12  16

a,b - c,d = dp[c][d]- (dp[c][b-1]+dp[a-1][d]-dp[a-1][b-1]);

dp[i][j]=dp[i-1][j]+dp[i][j-1]+dp[i-1][j-1]





*/