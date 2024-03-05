#include <iostream>
#include <vector>
using namespace std;
int N;
long long ans;
vector <int> dist;
vector <int> much;

void solve(){
    int cnt=1;
    int money=much[0];
    long long plus;
    for(int i=1;i<N;i++){
        if(money>much[i]){
            long long sumdis=0;
            for(int j=i-cnt;j<i;j++){
                sumdis+=dist[j];
            }
            ans+=sumdis*money;
            money=much[i];
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    if(cnt!=1){
        cnt-=1;
        long long lastdis=0;
        for(int j=dist.size()-cnt;j<dist.size();j++){
                lastdis+=dist[j];
            }
        ans+=lastdis*money;
    }
    cout <<ans;
}

int main(){
    cin >> N;
    int tmp;
    for(int i=0;i<N-1;i++){
        cin >> tmp;
        dist.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        cin >> tmp;
        much.push_back(tmp);
    }
    ans=0;
    solve();
    return 0;
}