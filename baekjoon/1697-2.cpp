#include <iostream>
#include <queue>
using namespace std;

bool visit[100001];


int main()
{
    int n,k;
    cin>>n>>k;
    queue<pair<int,int>> q;
    visit[n]=true;
    q.push({n,0});
    int cnt=0;
    while(!q.empty())
    {
        int cur = q.front().first;
        int num = q.front().second;
        q.pop();
        if(cur==k){
            cout<<num;
            break;
        }
        if(cur*2<100001){
            if(!visit[cur*2]){
                visit[cur*2]=true;
                q.push({cur*2,num+1});
            }
        }
        if(0<=cur-1){
            if(!visit[cur-1]){
                visit[cur-1]=true;
                q.push({cur-1,num+1});
                
            }
        }
        if(cur+1<100001){
            if(!visit[cur+1]){
                visit[cur+1]=true;
                q.push({cur+1,num+1});
                
            }
        }
    }
    return 0;
}