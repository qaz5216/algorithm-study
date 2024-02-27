#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9;
int V,E;
int st;

vector<pair<int,int>> edge[20001];
int arr[20001];

void solve()
{  
    for(int i=1;i<=V;i++)
        arr[i]=INF;
    arr[st]=0;
    queue<pair<int,int>> q;
    q.push({0,st});
    while (!q.empty())
    {
        pair<int,int> now=q.front();q.pop();
        for (pair<int,int> next : edge[now.second])
        {
            if (arr[next.first]>now.first+next.second)
            {
                arr[next.first]=now.first+next.second;
                q.push({now.first+next.second,next.first});
            }           
        }   
    }
}

void print()
{
    for(int i=1;i<=V;i++)
    {
        if(i==st)
        cout<<0<<endl;
        else if(arr[i]==1e9)
        cout<<"INF"<<endl;
        else
        cout<<arr[i]<<endl;
    }
}

int main()
{
    cin >> V >> E;
    cin >>st;
    for(int i=0;i<E;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[a].push_back({b,c});
    }
    //solve
    solve();
    //print
    print();
    return 0;
}