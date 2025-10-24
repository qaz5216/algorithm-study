#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans[8];
int arr[8];
bool visit[8];

void comb(int x,int idx){ //idx=for문시작위치
    if(x==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=idx;i<n;i++){
        if(visit[i])continue;
        visit[i]=true;
        ans[x]=arr[i];
        comb(x+1,i+1);//지금넣은거보다 큰거부터시작해
        visit[i]=false;
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);//정렬
    comb(0,0);
    return 0;
}