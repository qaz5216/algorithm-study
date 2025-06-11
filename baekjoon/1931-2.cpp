#include <iostream>
#include <queue>

using namespace std;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++)
    {
        int s,e;
        cin>>s>>e;
        pq.push({e,s});
    }
    int ans=0;
    int time=0;
    while(!pq.empty())
    {
        int s=pq.top().second;
        int e=pq.top().first;
        pq.pop();
        if(time>s) continue;
        time=e;
        ans++;
    }
    cout<<ans;
    return 0;
}