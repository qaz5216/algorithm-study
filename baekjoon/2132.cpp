#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[10001];
vector<int> edge[10001];
bool visit[10001];
int maxval=0;
int maxi=1;
int dp[10001];
void dfs(int x,int val)
{
    visit[x]=true;
    dp[x]=val;
    if(val>maxval)
    {
        maxi=x;
        maxval=val;
    }
    else if(val==maxval) // 답이 여러 개 있을 경우에는 정점의 번호가 가장 작은 경우를 출력한다
    {
        if(maxi>x){
        maxi=x;
        }
    }
    for(int next:edge[x])
    {
        if(!visit[next])
        dfs(next,val+arr[next]);
    }
}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> arr[i];
    }
    for(int i=1;i<N;i++)
    {
        int a,b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=N;i++)
    {
        visit[i]=false;
    }
    dfs(1,arr[1]);
    for(int i=1;i<=N;i++)
    {
        visit[i]=false;
    }
    int start=maxi;
    dfs(maxi,arr[maxi]);
    //답이 여러 개 있을 경우에는 정점의 번호가 가장 작은 경우를 출력한다
    start=min(start,maxi);//시작과 끝 둘다 답이 되기에 가장 작은번호출력
    
    cout<<maxval<<" "<<start;
    return 0;
}