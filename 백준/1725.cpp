#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int N;
ll ans=0;
ll hist[100001];

ll cal(int start,int end)
{
    if(start==end) return hist[start];
    ll l,r,mid;
    mid=(start+end)/2;
    l=mid;
    r=mid+1;
    ll result = max(cal(start,l),cal(r,end));

    ll h=min(hist[l],hist[r]);
    
    result=max(result,h*(r-l+1));
    while(start<l||r<end)
    {
        if(start==l)
        {
            h=min(h,hist[++r]);
        }
        else if(end==r)
        {
            h=min(h,hist[--l]);
        }
        else if(hist[l-1]>hist[r+1])
        {
            h=min(h,hist[--l]);
        }
        else
        {
            h=min(h,hist[++r]);
        }
        result=max(result,h*(r-l+1));
    }
    return result;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >>hist[i];
    }
    cout <<cal(0,N-1);
    return 0;
}