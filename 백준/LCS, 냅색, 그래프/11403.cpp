#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
bool map[101][101];
bool ans[101][101];

bool dp[101];

void print()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cout<<map[i][j]<<" ";
        }
        cout<< endl;
    }
}

void print2()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<< endl;
    }
}

void solve()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
            {
                if(map[j][i]&&map[i][k])
                    map[j][k]=true;
            }
}

void dfs(int now)
{
    for(int i=0;i<N;i++)
    {
        if (map[now][i]&&!dp[i])
        {
            dp[i]=true;
            dfs(i);
        }
        
    }
}

void solve2()
{
    for(int i=0;i<N;i++)
    {   
        memset(dp,false,sizeof(dp));
        dfs(i);
        for(int j=0;j<N;j++)
        {
            ans[i][j]=dp[j];   
        }
        
    }
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            bool tmp;
            cin >> tmp;
            map[i][j]=tmp;
        }
    }
    //solve
    
    //solve();
    solve2();
    
    //print
    
    //print();
    print2();
    
    return 0;
}