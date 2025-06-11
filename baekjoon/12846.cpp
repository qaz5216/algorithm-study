#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int N;
ll money[100001];

ll cal(int start,int end)
{
    if(start==end) return money[start];
    int l,r,mid;
    mid=(start+end)/2;
    l=mid;
    r=mid+1;
    ll result=max(cal(start,l),cal(r,end));
    ll h=min(money[l],money[r]);
    result=max(result,h*2);
    while (start<l||r<end)
    {
        if(start==l)
            h=min(h,money[++r]);
        else if(end==r)
            h=min(h,money[--l]);
        else if(money[l-1]>money[r+1])
            h=min(h,money[--l]);
        else
            h=min(h,money[++r]);
        result=max(result,h*(r-l+1));
    }
    return result;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin>>money[i];
    }
    cout << cal(0,N-1);
    return 0;
}