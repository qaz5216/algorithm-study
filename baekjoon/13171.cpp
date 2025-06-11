#include <iostream>

using namespace std;

#define ll long long

ll A,X;
ll INF=1e9+7;

ll namage(ll x)
{
    if(x==1) return A;
    ll k=namage(x/2)%INF;
    if(x%2==0)
        return k%INF*k%INF;
    else
    {
        return k%INF*k%INF*A%INF;
    }
    return 1;
}

int main()
{
    cin>> A >> X;
    A%=INF;
    cout<<namage(X)%INF;
    return 0;
}
