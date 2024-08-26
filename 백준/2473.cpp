#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> v;
int ans[3];
long long sum=3e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-2;i++)
    {
        if(sum==0) break;
        int l=i+1;
        int r=n-1;
        while(l<r){
            long long tmp = v[i]+v[l]+v[r];
            if(abs(tmp)<sum){
                sum=abs(tmp);
                ans[0]=v[i];
                ans[1]=v[l];
                ans[2]=v[r];
            }
            if(tmp==0) break;
            if(tmp<0) l++;
            else r--;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<" ";
    return 0;
}