#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool check[51];
bool sosu[2001];
bool exist[51][51];
int arr[51];
int d[51];
int c[51][51];

vector<int> edge[51];
vector<int> ans;

bool dfs(int x)
{
    for(int next:edge[x])
    {
        if(check[next]||c[x][next]<=0) continue;
        check[next]=true;
        if(d[next]==0||dfs(d[next]))
        {
            d[next]=x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }
    //소수 판별
    memset(sosu,true,sizeof(sosu));
    for(int i=2;i<2001;i++)
    {
        for(int j=2;i*j<2001;j++)
        {
            sosu[i*j]=false;
        }
    }
    //에지추가
    memset(exist,false,sizeof(exist));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            if(sosu[arr[i]+arr[j]])
            {
                if(c[i][j]>0) continue;
                edge[i].push_back(j);
                edge[j].push_back(i);
                c[i][j]+=1;
                c[j][i]+=1;
            }
        }
    }
    while(true)
    {
        memset(d,0,sizeof(d));
        for(int i=1;i<=N;i++)
        {
            memset(check,false,sizeof(check));
            dfs(i);
        }
        //검사
        bool flag=false;
        for(int i=1;i<=N;i++)
        {
            cout<<d[i]<<" ";
            if(d[i]==0)
                flag=true;
        }
        cout<<"\n";
        if(flag)
            break;
        ans.push_back(arr[d[1]]);
        c[1][d[1]]-=1;
        c[d[1]][1]-=1;
    }
    if(ans.size()==0)
    {
        cout<<-1;
    }
    else
    {
        sort(ans.begin(),ans.end());
        for(int answer:ans)
        {
            cout<<answer<<" ";
        }
    }
    return 0;
}