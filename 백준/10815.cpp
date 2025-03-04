#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        int l=0,r=n-1;
        bool flag=false;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a>arr[mid])
            {
                l=mid+1;
            }
            else if(a<arr[mid])
            {
                r=mid-1;
            }
            else
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
        cout<<' ';
    }
    return 0;
}