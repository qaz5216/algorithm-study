#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,Q;
int edge[200001];
int P[200001];
vector<pair<int,pair<int,int>>> query;
vector<string> ans;
int find(int x)
{
    if(x==P[x])
    {
        return x;
    }
    return P[x]=find(P[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)
        return;
    if(a>b)swap(a,b);
    P[b]=P[a];
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N>>Q;
    for(int i=2;i<=N;i++)
    {
        cin>>edge[i];
    }
    for(int i=0;i<Q+N-1;i++)
    {
        int a,b,c;
        cin>> a;
        if(a!=0)
        {
            cin>>b>>c;
            query.push_back({a,{b,c}});
        }
        else
        {
            cin>>b;
            query.push_back({a,{b,0}});
        }   
    }
    reverse(query.begin(),query.end());
    for(int i=1;i<=N;i++)
    {
        P[i]=i;
    }
    
    for(pair<int,pair<int,int>> q:query)
    {
        if(q.first==0)
        {
            myunion(q.second.first,edge[q.second.first]);
        }
        else
        {   
            if(find(q.second.first)==find(q.second.second))
            {
                ans.push_back("YES");
            }
            else
            {
                ans.push_back("NO");
            }
        }
    }
    reverse(ans.begin(),ans.end());
    for(string answer:ans)
    {
        cout<<answer<<"\n";
    }
}