#include <iostream>
#include <algorithm>

using namespace std;

int arr[15001];

int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l=0;
    int r=n-1;
    while(l<r)
    {
        if(arr[l]+arr[r]>m)
        {
            r--;
        }
        else if(arr[l]+arr[r]<m)
        {
            l++;
        }
        else
        {
            r--;
            l++;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}