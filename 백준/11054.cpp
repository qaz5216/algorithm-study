#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1001];
int rrecord[1001];
int main()
{
    int n,t,tmp,result=0;
    int arr[1001];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    record[n]=1;
    for(int i=n-1;i>0;i--){
        record[i]=1;
        for(int j=i+1;j<=n;j++){
            if(arr[i]>arr[j]){
                record[i]=max(record[j]+1,record[i]);
            }
        }
    }
    rrecord[1]=1;
    for(int i=2;i<=n;i++){
        rrecord[i]=1;
        for(int j=i-1;j>0;j--){
            if(arr[i]>arr[j]){
                rrecord[i]=max(rrecord[j]+1,rrecord[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        result=max(result,record[i]+rrecord[i]-1);
    }
    cout << result;
    return 0;
}
