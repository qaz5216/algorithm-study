#include <iostream>

using namespace std;
int n;
int arr[1000001];
int lis[1000001];

int binary_search(int s,int e,int value){
    if(s==e) return s;
    int mid=(s+e)/2;
    if(lis[mid]>=value){
        return binary_search(s,mid,value);
    }
    else{
        return binary_search(mid+1,e,value);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    lis[0]=arr[0];
    int len=0;
    for(int i=0;i<n;i++){
        if(arr[i]>lis[len]){
            len++;
            lis[len]=arr[i];
        }
        else{
            int idx=binary_search(0,len,arr[i]);
            lis[idx]=arr[i];
        }
    }
    cout<<len+1;
    return 0;
}