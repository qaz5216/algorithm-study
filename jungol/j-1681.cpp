
#include <iostream>
using namespace std;
int n;
int arr[13][13];    //길:비용
bool visit[13]; //방문처리
int ans=1e9;//최대값

void dfs(int x,int cost,int num){
    if(cost>=ans) return; //이거안하면 시간초과;; 이미 최소값보다 크면
    if(num==n){
        if(arr[x][0]==0) return; //돌아가는길 없으면 종료
        ans=min(ans,cost+arr[x][0]);//최소값 갱신
        //cost + 0 으로 돌아가는길
        return;
    }
    for(int i=0;i<n;i++){
        if(visit[i]||arr[x][i]==0)continue; //방문했거나 길이없으면
        visit[i]=true; //방문처리
        dfs(i,cost+arr[x][i],num+1); //방문
        visit[i]=false; //방문처리 풀기
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    visit[0]=true;  //0방문처리
    dfs(0,0,1); //개수 
    if(ans==1e9)cout<<0;
    else
    cout<<ans;  //출력
    return 0;
}
