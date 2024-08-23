#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    int l=1,r=k;
    while(l<r)
    {
        int mid=(l+r)/2;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt+=min(n,mid/i);
        }
        if(cnt>=k)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<r<<"\n";
    return 0;
}