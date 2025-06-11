#include <iostream>

using namespace std;

int n,m;
int arr[5001];
int ans=100001;

int main()
{
    cin>>n>>m;
    int l=0;
    int r=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        r=max(arr[i],r);
    }
    while(l<=r)
    {
        int mid=(l+r)/2;
        int cnt=1;
        int mn=arr[0];
        int mx=arr[0];
        for(int i=1;i<n;i++)
        {
            mn=min(mn,arr[i]);
            mx=max(mx,arr[i]);
            if(mx-mn>mid)
            {
                cnt++;
                mn=arr[i];
                mx=arr[i];
            }
        }
        if(cnt<=m)
        {
            ans=min(ans,mid);
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}