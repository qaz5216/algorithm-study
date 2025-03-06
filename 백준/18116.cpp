#include <iostream>

using namespace std;
//1000001

int num[1000001];
int p[1000001];

int find(int x)
{
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(a>b) swap(a,b);
    p[b]=a;
    num[a]+=num[b];
    num[b]=0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    for(int i=1;i<=1000000;i++){
        p[i]=i;
        num[i]=1;
    }
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char q;
        int a,b;
        cin>>q>>a;
        if(q=='I')
        {
            cin>>b;
            myunion(a,b);
        }
        else
        {
            int cnt=0;
            int t=find(a);
            cout<<num[t]<<'\n';
        }
    }
    return 0;
}