#include <iostream>

using namespace std;

#define ll long long
/*
42 9496 7295
*/

int main()
{
    ll n;
    cin>>n;
    ll i=1;
    while(i*(i+1)/2<=n)
    {
        i++;
    }
    cout<<i-1;
    return 0;
}