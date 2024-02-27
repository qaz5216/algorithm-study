#include <iostream>
#include <vector>
using namespace std;
int N;
int K;
int ans;
vector<int> arr;

void solve(int cnt){
    if(K/arr[cnt]>0){
        ans+=(K/arr[cnt]);
        K=K%arr[cnt];
    }
    if(cnt==0){
        return;
    }
    else{
        solve(cnt-1);
    }
    return;
}

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    ans=0;
    solve(N-1);
    cout << ans;
    return 0;
}