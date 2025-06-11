#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1001];
int main()
{
    int n,t,tmp,result=0;
    int arr[1001];
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    record[1]=1;
    for(int i=2;i<=n;i++){
        record[i]=1;
        for(int j=i-1;j>0;j--){
            if(arr[j]<arr[i])
                record[i]=max(record[i],record[j]+1);
        }
    }
    for (int i=1;i<=n;i++){
        result=max(result,record[i]);
    }
    cout << result;
    return 0;
}
