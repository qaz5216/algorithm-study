#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[200001];

int findx(int x){
    int l=0;int r=n-1;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(arr[mid]>=x)
        {
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(arr[l]==x)
        return l;
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        int res=findx(x);
        cout<<res<<"\n";
    }
    
    return 0;
}