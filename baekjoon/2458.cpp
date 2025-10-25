#include <iostream>

using namespace std;

int arr[502][502];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            arr[i][j]=1e9;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b;
        arr[a][b]=1;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(arr[i][j]!=1e9||arr[j][i]!=1e9)
                cnt++;
        }
        if(cnt==n-1) ans++;
    }
    cout<<ans;
    return 0;
}
