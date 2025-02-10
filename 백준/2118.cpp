#include <iostream>

using namespace std;

int n;
int arr[50001];
int ans;
int sum;

int main()
{
    cin>>n;
    sum=0;
    ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int s=0,e=0,tmp=0;
    while(s<n)
    {
        while(true)
        {
            tmp+=arr[e];
            if(tmp>sum/2)
            {
                tmp-=arr[e];
                break;
            }
            e++;
            if(e>=n)e-=n;
        }
        ans=max(ans,tmp);
        tmp-=arr[s];
        s++;
    }
    cout<<ans;
    return 0;
}