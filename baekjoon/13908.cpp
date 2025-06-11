#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
bool check[10];
int n,m;
int ans=0;

void C(int idx,int num)
{
    if(num==0)
    {
        ans+=pow(10,n-idx);
    }
    else if(idx+num<=n)
    {
        for(int i=0;i<10;i++)
        {
            if(check[i])
            {
                check[i]=false;
                C(idx+1,num-1);
                check[i]=true;
            }
            else
            {
                C(idx+1,num);
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        check[x]=true;
    }
    C(0,m);
    cout<<ans;
    return 0;
}