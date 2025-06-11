#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001];
int dist[10001];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        dist[i]=arr[i+1]-arr[i];
    }
    sort(dist,dist+n-1,greater<int>());
    int ans=0;
    for(int i=k-1;i<n-1;i++)
    {
        ans+=dist[i];
    }
    cout<<ans;
    return 0;
}

/*

1 3 6 / 6 7 9
*/