#include <iostream>

using namespace std;

int n,k;
int arr[101];
int ans[10001];

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=arr[i];j<=k;j++){
            if(arr[i]==j){
                ans[j]++;
            }
            else{
                ans[j]+=ans[j-arr[i]];
            }

        }
    }
    cout<<ans[k];
    return 0;
}
/*
*/