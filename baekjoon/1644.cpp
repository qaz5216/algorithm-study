#include <iostream>
#include <vector>

using namespace std;
int n;
bool isPrime[4000001];
vector<int> arr;
long long answer=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    if(n==0||n==1){
        cout<<0;
        return 0;
    }
    for(int i=2;i*i<=n;i++)
    {
        for(int j=i*2;j<=n;j+=i){
           isPrime[j]=true;
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i])continue;
        arr.push_back(i);
    }
    long long sum=arr[0];
    int l=0;
    int r=0;
    while(l<=r&&r<arr.size()){
        if(sum<n){
            r++;
            if(r<arr.size())
                sum+=arr[r];

        }
        else if(sum>n){
            sum-=arr[l];
            l++;
        }
        else{
            answer++;
            sum-=arr[l];
            r++;
            l++;
            if(r<arr.size())
                sum+=arr[r];
        }
    }
    cout<<answer;
    return 0;
}

/*
누적합
소수의...
투포인터로 시작과 끝 찾기
400만까지 소수를 어떻게 판별하지?
소수는 28만개..
투포인터 ㄱㄱ..?


*/