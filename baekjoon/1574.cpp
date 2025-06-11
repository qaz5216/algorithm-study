#include <iostream>
#include <cstring>
using namespace std;
int N,R,C;
bool blank[301][301];
bool check[301];
int V[301];
bool dfs(int x)
{
    for(int i=1;i<=C;i++)
    {
        if(check[i]||!blank[x][i]) continue;
        check[i]=true;
        if(V[i]==0||dfs(V[i]))
        {
            V[i]=x;
            return true;
        }
    }
    return false;
}
int main()
{
    cin>>R>>C>>N;
    memset(blank,true,sizeof(blank));
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin >> a >> b;
        blank[a][b]=false;
    }
    int cnt=0;
    for(int i=1;i<=R;i++)
    {
        memset(check,false,sizeof(check));
        if(dfs(i)) cnt++;
    }
    cout<< cnt;
    return 0;
}