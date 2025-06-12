#include <iostream>
#include <queue>
using namespace std;

int visit[1000000]; //1층=0
int f,s,g;
int dx[2]={0};
queue<pair<int,int>> q;


int main()
{
    cin>>f>>s>>g>>dx[0]>>dx[1];
    for(int i=0;i<=f;i++){
        visit[i]=1e9;
    }
    visit[0]=0;
    q.push({s,0});
    while(!q.empty())
    {
        int cur=q.front().first;
        int num=q.front().second;
        //cout<<cur<<','<<num<<'\n';
        q.pop();
        visit[cur]=num;
        for(int i=0;i<2;i++)
        {
            int next;
            if(i%2==0)
                next=cur+dx[i];
            else
                next=cur-dx[i];
            if(0<=next&&next<=f){
                if(visit[next]==1e9){
                    visit[next]=num+1;
                    q.push({next,num+1});
                }
            }
        }
    }

    if(visit[g]==1e9){
        cout<<"use the stairs";
    }
    else{
        cout<<visit[g];
    }
    return 0;
}