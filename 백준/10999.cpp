#include <iostream>

using namespace std;

#define ll long long

ll arr[1000001];
ll seg[4000004];
ll lazy[4000004];

void propagation(int node, int s, int e) {
    if (lazy[node] == 0) return;
    seg[node] += lazy[node] * (e - s + 1);
    if (s != e) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

ll initseg(int node,int s,int e)
{
    if(s==e) return seg[node]=arr[s];
    int mid=(s+e)/2;
    return seg[node]=initseg(node*2,s,mid)+initseg(node*2+1,mid+1,e);
}

ll update(int node,int s,int e,int l,int r,ll val)
{
    propagation(node,s,e);
    if(e<l||r<s) return seg[node];
    if(l<=s&&e<=r) 
    {
        lazy[node]+=val;
        propagation(node,s,e);
        return seg[node];
    }
    int mid=(s+e)/2;
    return seg[node]=update(node*2,s,mid,l,r,val)+update(node*2+1,mid+1,e,l,r,val);
}

ll query(int node,int s,int e,int l,int r)
{
    propagation(node,s,e);
    if(e<l||r<s) return 0;
    if(l<=s&&e<=r) return seg[node];
    int mid=(s+e)/2;
    return query(node*2,s,mid,l,r)+query(node*2+1,mid+1,e,l,r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    initseg(1,1,n);
    for(int i=0;i<m+k;i++)
    {
        ll a,b,c,d;
        cin>>a>>b>>c;
        if(b>c) swap(b,c);
        if(a==1)
        {
            cin>>d;
            update(1,1,n,b,c,d);
        }
        else{
            cout<<query(1,1,n,b,c)<<"\n";
        }
    }
    return 0;
}