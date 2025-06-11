#include <iostream>

using namespace std;

#define ll long long

int arr1[500001];
int arr2[1000001];
ll seg[2000004];

ll calc(int node,int s,int e,int l,int r)
{
    if(r<s||e<l) return 0;
    if(l<=s&&e<=r) return seg[node];
    int mid=(s+e)/2;
    return calc(node*2,s,mid,l,r)+calc(node*2+1,mid+1,e,l,r);
}

ll update(int node,int s,int e,int pos)
{
    if(pos<s||e<pos) return seg[node];
    if(s==e) return seg[node]+=1;
    int mid=(s+e)/2;
    return seg[node]=update(node*2,s,mid,pos)+update(node*2+1,mid+1,e,pos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr2[x]=i;
    }
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+=calc(1,0,n-1,arr2[arr1[i]],n-1);
        update(1,0,n-1,arr2[arr1[i]]);
    }
    cout<<cnt<<"\n";
    return 0;
}