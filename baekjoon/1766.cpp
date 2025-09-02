#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[32001];
priority_queue<int,
vector<int>,
greater<int>> pq;
int degree[32001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        degree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty())
    {
        int cur=pq.top();
        pq.pop();
        cout<<cur<<' ';
        for(int next:edge[cur]){
            degree[next]--;
            if(degree[next]==0){
                pq.push(next);
            }
        }
    }

    return 0;
}

/*
4 3
4-2
3-2
3-1

*/