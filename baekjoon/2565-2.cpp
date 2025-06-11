#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int>> v;
int dp[101];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(v[i].second>v[j].second)
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        result=max(result,dp[i]);
    }
    cout<<n-result;
    return 0;
}
