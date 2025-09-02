#include <iostream>
#include <vector>
using namespace std;

bool visit[1001];
vector<int> Prime;
int main()
{
    int t;
    cin>>t;
    for(int i=2;i<500;i++){
        for(int j=2;i*j<1000;j++){
            visit[i*j]=true;
        }
    }
    for(int i=2;i<1000;i++)
    {
        if(!visit[i]){
            Prime.push_back(i);
        }
    }
    while(t--){
        int k;
        cin>>k;
        bool flag=false;
        int i;
        int j;
        int t;
        for(i=0;i<Prime.size();i++){
            for(j=i;j<Prime.size();j++){
                int tmp=Prime[i]+Prime[j];
                int l=j;
                int r=Prime.size();
                int findv=k-tmp;
                while(l<r){
                    int mid=(l+r)/2;
                    if(Prime[mid]>=findv){
                        r=mid;
                    }
                    else{
                        l=mid+1;
                    }
                }
                if(findv==Prime[l]){
                    flag=true;
                    cout<<Prime[i]<<' '<<Prime[j]<<' '<<Prime[l]<<'\n';
                }
                if(flag)break;
            }
            if(flag)break;
        }
        if(!flag){
            cout<<0<<'\n';
        }
    }
    return 0;
}