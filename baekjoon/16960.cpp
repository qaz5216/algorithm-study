#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n,m;

vector<int> arr[2001];
unordered_map<int,int> cnt;

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        for(int j=0;j<c;j++){
            int x;
            cin>>x;
            arr[i].push_back(x);
            cnt[x]++;
        }
    }
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int x:arr[i]){
            if(cnt[x]<=1){
                flag=false;
            }
        }
        if(flag){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}