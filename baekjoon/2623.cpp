#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[1001];
vector<int> answer;
int degree[1001];
queue<int> q;

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int t;
        cin>>t;
        int prev;
        cin>>prev;
        t=t-1;
        while(t--)
        {
            int tmp;
            cin>>tmp;
            degree[tmp]++;
            edge[prev].push_back(tmp);
            prev=tmp;
        }
    }
    for(int i=1;i<=n;i++){
            if(degree[i]==0)q.push(i);
        }
        while (!q.empty())
        {
            int cur=q.front();
            q.pop();
            answer.push_back(cur);
            for(int next:edge[cur]){
                degree[next]--;
                if(degree[next]==0){
                    q.push(next);
                }
            }
        }
        if(answer.size()!=n){
            cout<<0;
        }
        else{
            for(int ans:answer){
                cout<<ans<<'\n';
            }
        }
    return 0;
}