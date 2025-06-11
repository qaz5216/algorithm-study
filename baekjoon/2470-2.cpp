#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    int l=0,r=arr.size()-1;
    int mn=abs(arr[l]+arr[r]);
    int al=0,ar=arr.size()-1;
    while(l<r)
    {
        if(mn>abs(arr[l]+arr[r]))
        {
            mn=abs(arr[l]+arr[r]);
            al=l;ar=r;
        }
        if(arr[l]+arr[r]>0)
        {
            r-=1;
        }
        else
        {
            l+=1;
        }
    }
    cout<<arr[al]<<" "<<arr[ar];
    return 0;
}