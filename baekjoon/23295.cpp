#include <iostream>

using namespace std;

int n,t,num;
int arr[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    int s,e;
    for(int i=0;i<n;i++){
        cin>>num;
        for(int j=0;j<num;j++){
            cin>>s>>e;
            arr[s]+=1;
            arr[e]-=1;
        }
    }
    long long mx=0;
    long long ans=0;
    int start=0;
    int cnt=0;
    for(int i=0;i<t;i++){
        cnt+=arr[i];
        arr[i]=cnt;
        mx+=arr[i];
    }
    ans=mx;
    for(int i=t;i<100001;i++){
        cnt+=arr[i];
        arr[i]=cnt;
        mx+=arr[i];
        mx-=arr[i-t];
        if(mx>ans){
            start=i+1-t;
            ans=mx;
        }
    }
    cout<<start<<' '<<start+t<<'\n';
    return 0;
}