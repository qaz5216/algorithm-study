#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
vector<int> basic;
vector<pair<int,int>> edge[101];
bool check[101];
int num[101];
int degree[101];
queue<int> q;

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
        degree[b]++;
    }
    q.push(n);
    num[n]=1;
    while (!q.empty())
    {
        int cur=q.front();
        q.pop();
        if(edge[cur].size()==0)check[cur]=true;
        for(pair<int,int> np:edge[cur])
        {
            int next=np.first;
            int weight=np.second;
            num[next]+=weight*num[cur];
            degree[next]--;
            if(degree[next]==0){
                q.push(next);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(check[i]){
            cout<<i<<' '<<num[i]<<'\n';
        }
    }
    return 0;
}