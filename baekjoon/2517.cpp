#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define ll long long

int N;
vector<int> arr;
int arr2[500001];
int dp[500001];
map <int,int> power;
int seg[2000001];


ll update(int node,int s,int e,int pos)
{
    if(pos<s||e<pos) return seg[node];
    if(s==e) return seg[node]=seg[node]+1;
    int mid=(s+e)/2;
    return seg[node]=update(node*2,s,mid,pos)+update(node*2+1,mid+1,e,pos);
}

ll query(int node, int l, int r, int s, int e) {
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return seg[node];
    int mid = (l + r) / 2;
    return query(node * 2, l, mid, s, e) + query(node * 2 + 1, mid + 1, r, s, e);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>> N;
    for(int i=0;i<N;i++)
    {
        cin>>dp[i];
        arr.push_back(dp[i]);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<N;i++)
    {
        power[arr[i]]=i+1;
    }
    for(int i=0;i<N;i++)
    {
        cout<<(i+1)-query(1,0,N-1,0,power[dp[i]]-1)<<"\n";
        if(i!=N-1)
        update(1,0,N-1,power[dp[i]]-1);
        }
    return 0;
}