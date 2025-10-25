#include <iostream>

using namespace std;

int n,m;
int arr[8];
bool visit[9];
void comb(int cur){
    if(cur==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(visit[i])continue;
        arr[cur]=i;
        visit[i]=true;
        comb(cur+1);
        visit[i]=false;
    }
}

int main()
{
    cin>>n>>m;
    comb(0);
    return 0;
}