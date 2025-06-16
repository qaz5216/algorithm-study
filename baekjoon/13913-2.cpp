#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,k;
int p[100001];
bool visit[100001];
int dx[2]={1,-1};
priority_queue<pair<int,int>,
vector<pair<int,int>>,
greater<pair<int,int>>
> pq;

int main()
{
    cin>>n>>k;
    for(int i=0;i<100001;i++)
    {
        p[i]=-1;
    }
    p[n]=n;
    visit[n]=true;
    pq.push({0,n});
    while (!pq.empty())
    {
        int cur=pq.top().second;
        int num=pq.top().first;
        pq.pop();
        if(cur==k){
            cout<<num<<"\n";
            break;
        }
        int next2=cur*2;
        if(next2<100001){
            if(!visit[next2]){
                p[next2]=cur;
                visit[next2]=true;
                pq.push({num+1,next2});
            }
        }
        for(int i=0;i<2;i++)
        {
            int next=cur+dx[i];
            if(0<=next&&next<100001)
            {
                if(!visit[next]){
                    p[next]=cur;
                    visit[next]=true;
                    pq.push({num+1,next});
                }
            }
        }
    }
    vector<int> ans;
    for(int i=k;p[i]!=i;){
        ans.push_back(i);
        i=p[i];
    }
    ans.push_back(n);
    reverse(ans.begin(),ans.end());
    for(int x:ans)
    {
        cout<<x<<' ';
    }
    return 0;
}