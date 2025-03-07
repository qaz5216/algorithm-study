#include <iostream>

using namespace std;

int n;
int arr[10003];

int main()
{
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i+1]>arr[i+2])
        {
            int cnt = min(arr[i], arr[i+1] - arr[i+2]);
            ans+=5*cnt;

            arr[i]-=cnt;
            arr[i+1]-=cnt;
            
            int cnt2 = min(arr[i], min(arr[i+1], arr[i+2]));
            ans+=7*cnt2;

            arr[i]-=cnt2;
            arr[i+1]-=cnt2;
            arr[i+2]-=cnt2;
        }
        else
        {
            int cnt = min(arr[i],min(arr[i+1], arr[i+2]));
            ans+=7*cnt;

            arr[i]-=cnt;
            arr[i+1]-=cnt;
            arr[i+2]-=cnt;
            
            int cnt2 = min(arr[i],arr[i+1]);
            ans+=5*cnt2;
            
            arr[i]-=cnt2;
            arr[i+1]-=cnt2;
        }
        ans+=3*arr[i];
    }
    cout<<ans;
    return 0;
}
