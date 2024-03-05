#include <iostream>
#include <vector>
using namespace std;

int p[300001];

int find(int x)
{
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
}

void myunion(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a>b)
        p[a]=b;
    else
        p[b]=a;
}

int main()
{
    int N;

    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<N;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<N-2;i++)
    {
        int a,b;
        cin >>a >> b;
        myunion(a,b);
    }
    for(int i=1;i<N;i++)
    {
        if(find(i)!=find(i+1))
        {
            cout<< i <<" "<< i+1;
            return 0;
        }
    }

    return 0;
}