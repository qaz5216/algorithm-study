#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1000001];


int main()
{
    int n,k,tmp,result;
    cin >> n >> k;
    tmp=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){ 
            tmp++;
        }
        if(tmp==k){
            result=i;
            cout << result;
            return 0;
        }
    }
    cout << 0;
    return 0;
}