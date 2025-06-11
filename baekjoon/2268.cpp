//세그먼트 트리
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int N,M;
ll seg[4000001];
vector<ll> ans;

ll query(int node,int start,int end,int left,int right)
{
    if(end<left||right<start) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid =(start+end)/2;
    return query(node*2,start,mid,left,right)+query(node*2+1,mid+1,end,left,right);
}

ll update(int node,int start,int end,int pos,int value)
{
    if(pos<start||end<pos) return seg[node];
    if(start==end) return seg[node]=value;
    int mid=(start+end)/2;
    return seg[node]=update(node*2,start,mid,pos,value)+update(node*2+1,mid+1,end,pos,value);
}


int main()
{
    cin >> N >> M;
    while(M--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a==0)
        {
            if(b>c) swap(b,c);
            ans.push_back(query(1,0,N-1,b-1,c-1));
        }
        else
        {
            update(1,0,N-1,b-1,(ll)c);
        }
    }
    for(ll answer:ans)
    {
        cout<< answer<<"\n";
    }
    return 0;
}
/* 
//펜윅트리
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
vector<ll> tree; 
int n, m;


void modify(int idx,ll diff) { 
    while(idx <= n) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll prefixSum(int idx) { 
    ll result = 0;
    while(idx > 0) {
        result += tree[idx];
        idx -= (idx & -idx);
    }
    return result;
}



ll sum(int start, int end) {
    return prefixSum(end) - prefixSum(start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);\
    int cmd, i, j;
    vector<int> arr;

    cin >> n >> m;
    arr.assign(n+1, 0);
    tree.assign(n+1, 0);
    while(m--) {
        cin >> cmd >> i >> j;
        if(cmd == 0) { 
            if(i > j) 
                swap(i, j);
            cout << sum(i-1, j) << '\n';
        }
        else if(cmd == 1) {
            ll diff = j - arr[i];
            arr[i] = j;
            modify(i, diff);
        }
    }
    return 0;
}
*/
