#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define ll long long

ll nn;
int kk;

ll f(ll n,int k)
{
    string s=to_string(n);
    if(k<=count(s.begin(),s.end(),'5')) return n;
    n/=10;
    if(s.back()>'5')
    {
        s=to_string(++n);
        if(k<=count(s.begin(),s.end(),'5')) return n*10;
    }
    return f(n,k-1)*10+5;
}

int main()
{
    cin>>nn>>kk;
    ll ans=f(nn+1,kk);
    cout<<ans;
    return 0;
}