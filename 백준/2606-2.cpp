#include <iostream>
#include <vector>

using namespace std;

int n,m;
bool map[101][101];
int ans=0;
bool check[101];

void printmap()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<< map[i][j]<< " ";
        }
        cout << endl;
    }
}

void solve()
{
    //printmap();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(map[j][i]&&map[i][k]&&j!=k)
                    map[j][k]=true;
            }   
        }
    }
}


int main()
{   
    cin >>n >> m;
    //초기화
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            map[i][j]=false;
        }
        check[i]=false;
    }
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        map[a][b]=true;
        map[b][a]=true;
    }
    //solve
    solve();

    //print
    //printmap();
    for(int i=1;i<=n;i++)
    {
        if(map[1][i])
        ans++;
    }
    cout<<ans;
    return 0;
}