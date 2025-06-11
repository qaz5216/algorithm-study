#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
pair<int,int> p[1001][1001];
vector<char> ans;

int main()
{
    pair<int,int> idx;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();i++)
    {
        for(int j=0;j<s2.size();j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
                p[i+1][j+1]={i,j};
                if(dp[idx.first][idx.second]<dp[i+1][j+1])
                {
                    idx={i+1,j+1};
                }
            }
            else
            {
                if(dp[i+1][j]>=dp[i][j+1])
                {
                    dp[i+1][j+1]=dp[i+1][j];
                    p[i+1][j+1]={i+1,j};
                }
                else
                {
                    dp[i+1][j+1]=dp[i][j+1];
                    p[i+1][j+1]={i,j+1};
                }
            }
        }
    }
    if(dp[idx.first][idx.second]==0)
    {
        cout<<dp[idx.first][idx.second];
        return 0;    
    }
    cout<<dp[idx.first][idx.second]<<"\n";
    pair<int,int> cur=idx;
    pair<int,int> next=p[cur.first][cur.second];
    ans.push_back(s1[cur.first-1]);
    while(cur.first!=next.first||cur.second!=next.second)
    {
        cur=next;
        next=p[cur.first][cur.second];
        if(dp[cur.first][cur.second]!=dp[next.first][next.second])
        {
            ans.push_back(s1[cur.first-1]);
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i];
    }
    return 0;
}