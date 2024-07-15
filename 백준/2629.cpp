#include <iostream>

using namespace std;

int n,m;
int chu[31];
int goo[8];
bool dp[31][15001];

void dfs(int i,int w)
{
    if(i>n||dp[i][w]) return;
    dp[i][w]=true;
    dfs(i+1,w+chu[i]);
    dfs(i+1,abs(w-chu[i]));
    dfs(i+1,w);
}

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>chu[i];
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin>>goo[i];
    }
    dfs(0,0);
    for(int i=0;i<m;i++)
    {
        if(goo[i]>15000) cout<<"N ";
        else if(dp[n][goo[i]]) cout<<"Y ";
        else cout<<"N ";
    }
    return 0;
}