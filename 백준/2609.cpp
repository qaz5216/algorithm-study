#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int>> arr;


int main()
{
    int n,k,tmp;
    pair<int,int> result;
    cin >> n >> k;
    if(k>n){
        tmp=n;
        n=k;
        k=tmp;
    }
    for(int i=1;i<=k;i++){
        if(n%i==0&&k%i==0)
            {
                result.first=i; 
            }
    }
    for(int i=1;i<=k;i++){
        if((n*i)%k==0){
           result.second=n*i;
           break; 
        }
    }
    cout << result.first <<"\n"<<result.second;
    return 0;
}