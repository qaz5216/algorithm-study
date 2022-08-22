#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define INF 10000001;
int n,m;
int arr[101][101];
int dp[101][101];

struct bus
{
    int a,b,c;
};
vector<bus> buses;

int main(){
    cin >> n;    
    cin >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            arr[i][j]=INF;
    }
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        buses.push_back({x,y,z});
    }
    for(bus e: buses){
        if(arr[e.a][e.b]==0)
            {
                arr[e.a][e.b]=e.c;
            }
        else if(arr[e.a][e.b]>e.c)
            {
                arr[e.a][e.b]=e.c;
            }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++){
                if(arr[j][i]!=10000001 && arr[i][k]!=10000001)
                    arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
            }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j || arr[i][j]==10000001)
                cout << "0" << " ";
            else
            cout << arr[i][j] << " ";
        }
    cout << "\n";
    }
    return 0;
}