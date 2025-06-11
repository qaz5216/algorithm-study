#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int ans=0;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int dist1=arr[j]-arr[i];
                int dist2=arr[k]-arr[j];
                if(dist1<=dist2&&2*(dist1)>=dist2)
                    ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

/*
1 0000 0000
*/