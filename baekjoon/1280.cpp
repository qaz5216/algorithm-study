#include <iostream>

using namespace std;

#define ll long long

const ll MOD=1000000007;

pair<ll,ll> seg[800001];
ll X[200001];


pair<ll,ll> update(int node,ll s,ll e,ll pos)
{
    if(pos<s||e<pos) return seg[node];
    if(s==e) {
        seg[node].first+=1;
        seg[node].second+=pos;
        return seg[node];}
    int mid=(s+e)/2;
    pair<ll,ll>left=update(node*2,s,mid,pos);
    pair<ll,ll>right=update(node*2+1,mid+1,e,pos);
    ll first=left.first+right.first;
    ll second=left.second+right.second;
    return seg[node]={first,second};
}

pair<ll,ll> query(int node,ll s,ll e,ll l,ll r)
{
    if(r<s||e<l) return {0,0};
    if(l<=s&&e<=r) return seg[node];
    int mid=(s+e)/2;
    pair<ll,ll>left=query(node*2,s,mid,l,r);
    pair<ll,ll>right=query(node*2+1,mid+1,e,l,r);
    ll first=left.first+right.first;
    ll second=left.second+right.second;
    return {first,second};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    ll ans=1;
    if(n==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>X[i];
        if(i!=1){
            pair<ll,ll> lq=query(1,0,200000,0,X[i]);
            pair<ll,ll> rq=query(1,0,200000,X[i],200000);
            ll lcost=abs(lq.first*X[i]-lq.second);
            ll rcost=abs(rq.first*X[i]-rq.second);
            ans=(((lcost+rcost)%MOD)*ans)%MOD;
        }
        update(1,0,200000,X[i]);
    }
    cout<<ans;
    return 0;
}