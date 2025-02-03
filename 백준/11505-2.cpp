#include <iostream>

using namespace std;

#define ll long long

const ll Mx=1000000007;
ll arr[1000001];
ll tree[1000001];
bool zero[1000001];
int zerosum[1000001];
int n,m,k;

ll pow(int x,int n) {
    if(n==1) return x;
    ll half=pow(x,n/2);
    if(n%2==0) return half*half%Mx;
    else return (half*half%Mx)*x%Mx;
}

ll moduloinverse(int x) {
    return pow(x,Mx-2);
}

void Update(int idx, ll mul)
{
    while(idx<=n)
    {   
        tree[idx]=(tree[idx]*mul)%Mx;
        idx=idx+(idx&-idx);
    }
}

void Updatezero(int idx, int val)
{
    while(idx<=n)
    {   
        zerosum[idx]=zerosum[idx]+val;
        idx=idx+(idx&-idx);
    }
}

int iszero(int idx)
{
    if(idx==0) return 0;
    int ans=0;
    while(idx>0)
    {
        ans+=zerosum[idx];
        idx-=(idx&-idx);
    }
    return ans;
}

void initTree()
{
    for(int i=1;i<=n;i++)
    {
        tree[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        Update(i,arr[i]);
    }
}

ll Print(int idx)
{
    long long ans=1;
    while(idx>0)
    {
        ans=ans*tree[idx]%Mx;
        idx-=(idx&-idx);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]==0)
        {
            arr[i]=1;
            Updatezero(i,1);
            zero[i]=true;
        }
    }
    initTree();
    for(int i=1;i<=m+k;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1)
        {
            //zerosum검사
            if(zero[b]){
                if(c!=0){
                    zero[b]=false;
                    Updatezero(b,-1);
                    Update(b,c);
                    arr[b]=c;
                }
            }
            else{
                if(c==0){
                    zero[b]=true;
                    Updatezero(b,1);
                    Update(b,moduloinverse(arr[b]));
                    arr[b]=1;
                }
                else{
                    Update(b,moduloinverse(arr[b]));
                    Update(b,c);
                    arr[b]=c;
                }
            }
        }
        else
        {
            if(iszero(c)-iszero(b-1)>0) cout<<0<<"\n";
            else{
                if(b==1){
                    cout<<Print(c)%Mx<<"\n";
                }
                else{
                cout<<(Print(c)*moduloinverse(Print(b-1)))%Mx<<"\n";
                }
            }
        }
    }
    return 0;
}
