#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n,m,k;
vector<int> edge[200001];
queue<int> del;


bool flag=false;
int degree[200001];
bool visit[200001];
bool can[200001];
void dfs(int cur,int prev){
    if(flag)return;
    visit[cur]=true;
    for(int next:edge[cur]){
        if(!can[next])continue;
        if(next==prev)continue;
        if(visit[next]){
            flag=true;
        }
        else{
            visit[next]=true;
            dfs(next,cur);
        }
    }
}

void bfs(int st){
    queue<pair<int,int>> q;
    degree[st]=1;
    q.push({st,1});
    while(!q.empty()){
        int cur=q.front().first;
        int curt=q.front().second;
        for(int next:edge[cur]){
            if(degree[next]!=0)continue;
            degree[next]=curt+1;
            q.push({next,curt+1});
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    while(k--){
        int x;
        cin>>x;
        bfs(x);//사라지는 순서 구하기
    }
    /*
    제일늦게 사라진거부터 살려서
    dfs
    그다음으로 늦게사라진거 살리고 
    dfs
    반복
    */
    return 0;
}

/*
사이클 경로가 여러개 있는경우가 있겠지?
1-2-3-4-1
1-2-3-5-1
1-2-3-6-1
1-7-1
이런식으로?
어떻게 1번으로 시작하면 사이클이 없어졌는지 체크가능해?



*/