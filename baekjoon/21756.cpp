#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    int ans=1;
    for(;ans<=n;ans*=2);
    cout<<ans/2;
    return 0;
}