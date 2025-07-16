#include <iostream>

using namespace std;

#define ll long long

ll arr[100001];
ll seg[400004];

void initseg(int node, int s, int e)
{
    if (s == e)
    {
        seg[node] = arr[s];
        return;
    };
    int mid = (s + e) / 2;
    initseg(node * 2, s, mid);
    initseg(node * 2 + 1, mid + 1, e);
}

void update(int node, int s, int e, int l, int r, int val)
{
    if (e < l || r < s)
        return;
    if (l <= s && e <= r)
    {
        seg[node] += val;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    return;
}

ll query(int node, int s, int e, int pos, ll sum)
{
    if (e < pos || pos < s)
        return 0;
    sum += seg[node];
    if (s == e)
        return sum;
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, pos, sum) + query(node * 2 + 1, mid + 1, e, pos, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    initseg(1, 1, n);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c >> d;
            if (b > c)
                swap(b, c);
            update(1, 1, n, b, c, d);
        }
        else
        {
            cout << query(1, 1, n, b, 0) << "\n";
        }
    }

    return 0;
}
/* lazy solution

#include <iostream>

using namespace std;

#define ll long long

ll arr[100001];
ll seg[400004];
ll lazy[400004];

void propagation(int node,int s,int e)
{
    if(lazy[node]==0) return;
    seg[node]+=lazy[node]*(e-s+1);
    if(s!=e)
    {
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
    return;
}

ll initseg(int node,int s,int e)
{
    if(s==e) return seg[node]=arr[s];
    int mid=(s+e)/2;
    return seg[node]=initseg(node*2,s,mid)+initseg(node*2+1,mid+1,e);
}

ll update(int node,int s,int e,int l,int r,int val)
{
    propagation(node,s,e);
    if(e<l||r<s) return seg[node];
    if(l<=s&&e<=r){
        lazy[node]+=val;
        propagation(node,s,e);
        return seg[node];
    }
    int mid=(s+e)/2;
    return seg[node]=update(node*2,s,mid,l,r,val)+update(node*2+1,mid+1,e,l,r,val);
}

ll query(int node,int s,int e,int pos)
{
    propagation(node,s,e);
    if(e<pos||pos<s) return 0;
    if(s==e) return seg[node];
    int mid=(s+e)/2;
    return query(node*2,s,mid,pos)+query(node*2+1,mid+1,e,pos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    initseg(1,1,n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c,d;
        cin>>a>>b;
        if(a==1)
        {
            cin>>c>>d;
            if(b>c) swap(b,c);
            update(1,1,n,b,c,d);
        }
        else
        {
            cout<<query(1,1,n,b)<<"\n";
        }
    }

    return 0;
}

*/