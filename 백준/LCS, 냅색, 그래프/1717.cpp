#include <iostream>
#include <vector>

using namespace std;
int n,m;
int group[1000001];
vector<bool> ans;



bool isunion(int a,int b)
{
    if (group[a]==group[b])
    {
        return true;
    }
    if(a!=group[a]||b!=group[b])
    {
        return isunion(group[a],group[b]);
    }
    return false;
}

int find(int x)
{
    if (group[x]==x) return x;
    return find(group[x]);
}

void myunion(int a, int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a<=b)
        group[b]=a;
    else
        group[a]=b;
}

int main()
{
    cin >> n>>m;
    for(int i=0;i<=n;i++)
    {
        group[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int op,a,b;
        cin >> op >> a >> b;
        if(op==0)
        {
            myunion(a,b);
        }
        else{
            ans.push_back(isunion(a,b));
        }
    }
    for(bool what:ans)
    {
        if(what)
            cout<<"YES"<<"\n";
        else    
            cout<<"NO"<<"\n";
    }
    return 0;
}