#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> arr[1001];
int record[1001];

void dfs(int n) {
    for(int e : arr[n]) {
        if(record[e]==0){
        record[e] = true;
        dfs(e);
        }
    }
}
int main(){
    int n,m,a,b,result=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(record[i]==0){
            result++;
            record[i]=1;
            dfs(i);
        }
        cout << result;
    return 0;
}