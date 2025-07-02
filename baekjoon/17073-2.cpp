#include <iostream>
#include <vector>

using namespace std;

int n,w;
//리프노드 개수구하기
int cnt[500001];
int ans=0;
int main(){
    cin>>n>>w;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        cnt[u]++;
        cnt[v]++;
    }
    for(int i=2;i<=n;i++)
    {
        if(cnt[i]==1){
            ans++;
        }
    }
    cout<<(double)w/ans<<'\n';

    return 0;
}