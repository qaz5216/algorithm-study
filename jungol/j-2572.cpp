#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int ans=0;
int n,d,k,c;
bool check[30001];
int arr[30001];
bool exsist=false;
int main()
{
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        memset(check,false,sizeof(check));
        check[c]=true;
        cnt=1;
        for(int j=0;j<k;j++)
        {
            int idx=i+j;
            if(idx>=n){
                idx-=n;
            }
            if(!check[arr[idx]]){
                check[arr[idx]]=true;
                cnt++;
            };
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}