#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int mn=1000000;
bool check[1000001];
void bfs(int x,int y,int n){
    queue<pair<int,int>> q;
    check[x]=false;
    q.push(make_pair(x,0));
    while(!q.empty())
    {
        pair<int,int> tmp=q.front();
        q.pop();
        check[tmp.first]=false;
        if(tmp.first*2==y||tmp.first*3==y||tmp.first+n==y){
            mn=tmp.second+1;
            return;
        }
        if(tmp.first*2<y&&check[tmp.first*2])
            q.push(make_pair(tmp.first*2,tmp.second+1));
        if(tmp.first*3<y&&check[tmp.first*3])
            q.push(make_pair(tmp.first*3,tmp.second+1));
        if(tmp.first+n<y&&check[tmp.first+n])
            q.push(make_pair(tmp.first+n,tmp.second+1));
    }
    return;
}

int solution(int x, int y, int n) {
    int answer = 0;
    memset(check,true,sizeof(check));
    if(x==y)
        return 0;
    bfs(x,y,n);
    if(mn==1000000)
        return -1;
    return mn;
}