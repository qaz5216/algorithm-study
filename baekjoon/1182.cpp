#include <iostream>
#include <algorithm>

using namespace std;

int n,s;
int ans;
int arr[21];
bool check[21];
void comb(int cur){
    if(cur==n){
        bool flag=false;
        int sum=0;
        for(int i=0;i<n;i++){
            if(check[i]){sum+=arr[i];flag=true;}
        }
        if(flag&&sum==s)ans++;
        return;
    }
    else{
        comb(cur+1);
        check[cur]=true;
        comb(cur+1);
        check[cur]=false;
    }
}
int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ans=0;
    comb(0);
    cout<<ans;
    return 0;
}