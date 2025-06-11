#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char P[100];
long long ans=0;
vector<int> edge[100];
bool findflag=true;
int water[100][100];

bool existedge(int start,int end)
{
    for(int i=0;i<edge[start].size();i++)
    {
        if (edge[start][i]==end)
        {
            return true;
        }
    }
    for(int i=0;i<edge[end].size();i++)
    {
        if (edge[end][i]==start)
        {
            return true;
        }
    }
    return false;
}

void dfs(int cur,int minval,vector<int> tmp)
{
    if(!findflag)
        return;
    tmp.push_back(cur);
    if(cur=='Z'-'A')
    {
        for(int i=0;i<tmp.size()-1;i++)
        {
            water[tmp[i]][tmp[i+1]]-=minval;    
        }
        ans+=minval;
        findflag=false;
        return;
    }
    for(int next:edge[cur])
    {
        bool flag =true;
        for(int e:tmp)
        {
            if(e==next)
                flag=false;
        }
        if(flag&&water[cur][next]>0){
            dfs(next,min(minval,water[cur][next]),tmp);
        }
    }
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char x,y;
        int w;
        cin>>x>>y>>w;
        if(existedge(x-'A',y-'A')==false){
        edge[y-'A'].push_back(x-'A');
        edge[x-'A'].push_back(y-'A');
        water[x-'A'][y-'A']=w;
        water[y-'A'][x-'A']=w;
        }
        else{
            water[x-'A'][y-'A']+=w;
            water[y-'A'][x-'A']+=w;
        }
    }
    for(int i=0;i<100;i++)
    {
        P[i]=i;
    }
    while(1){
    findflag=true;
    vector <int> vec;
    dfs(0,702,vec);
    if(findflag)
        break;
    }
    cout<<ans;
}