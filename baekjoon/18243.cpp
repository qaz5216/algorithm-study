#include <iostream>

using namespace std;

int n,k;

int dist[101][101];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            dist[i][j]=101;
    }
    while(k--){
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dist[j][k]>dist[j][i]+dist[i][k]){
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
            }
        }
     }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(dist[i][j]>6){
                cout<<"Big World!";
                return 0;
            }
        }
    }
    cout<<"Small World!";
    return 0;
}