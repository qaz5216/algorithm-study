#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int record[101][100001];

int main(){
    int n,k,w,m;
    vector <pair<int,int>> arr;
    cin >> n >> k;
    arr.push_back({0,0});
    for(int i=0;i<n;i++){
        cin >> w >> m;
        arr.push_back({w,m});
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=k;j++){
            if(j-arr[i].first>=0){
                record[i][j]=max(record[i-1][j],record[i-1][j-arr[i].first]+arr[i].second);
            }
            else
                record[i][j]=record[i-1][j];
        }
    }

    cout << record[n][k];
    return 0;
}