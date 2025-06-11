#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector <pair<int,int>> q;
int P[1001];
int ans[1001];


int find(int x)
{
    if(P[x]==x) return x;
    return P[x]=find(P[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a>b) swap(a,b);
    P[b]=a;
    return;    
}

int main()
{
    cin >> N >> M;
    if(M<N-1){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<N;i++)
    {
        P[i]=i;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            char a;
            cin>>a;
            if(i<j){
                if(a=='N')continue;
                if(find(i)==find(j)) q.push_back({i,j});
                else{
                ans[i]++;
                ans[j]++;
                myunion(i,j);
                }
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        if(find(i)!=0)
        {
            cout<<-1;
            return 0;
        }
    }
    if(q.size()<M-N+1)
    {
        cout<<-1;
        return 0;
    }
    for(int i=0;i<M-N+1;i++)
    {
        ans[q[i].first]++;
        ans[q[i].second]++;
    }
    for(int i=0;i<N;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}