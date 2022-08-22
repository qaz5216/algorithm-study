#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main(){
    int N,M;
    cin >> N >> M;
    int T;
    for(int i=0;i<N;i++){
        cin >> T;
        arr.push_back(T);
    }
    sort(arr.begin(),arr.end());
    int end=arr[N-1];
    long long start=1; //long long 이유2 
    long long mid; //long long 이유1
    long long csum;
    int max=0;
    while(end-start>=0){
    mid=(end+start)/2; // 이유1 mid int로 커버안됨
    csum=0;
    for(int i=0;i<N;i++){
        csum+=(arr[i]/mid);
    }
    if(csum<M)
        end=mid-1;
    else{
        start=mid+1; //이유 2최악의경우 start가 정확히 2^31되버림
        if(max<mid)
            max=mid;
    }    
    }
    cout << max;
    return 0;
}