#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[500001];

int main()
{
    cin>>n;
    long long sum=0;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        sum-=arr[i];
        ans+=(sum)*arr[i];
    }
    cout<<ans;
    return 0;
}
