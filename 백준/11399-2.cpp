#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        ans+=(n-i)*arr[i];
    }
    cout<<ans;
    return 0;
}