#include <iostream>

using namespace std;

int arr1[1000001];
int arr2[1000001];
int sarr[1000001];
int n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int l=0,r=0;
    for(int i=0;i<n+m;i++)
    {
        if(l!=n&&r!=m)
        {
            if(arr1[l]<arr2[r])
            {
                sarr[i]=arr1[l];
                l++;
            }
            else
            {
                sarr[i]=arr2[r];
                r++;
            }
        }
        else if(l==n){
            sarr[i]=arr2[r];
            r++;
        }
        else if(r==m)
        {
            sarr[i]=arr1[l];
            l++;
        }
    }
    for(int i=0;i<n+m;i++)
    {
        cout<<sarr[i]<<' ';
    }
    return 0;
}