#include <iostream>
#include <algorithm>
using namespace std;
int n;
int sum=0;
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first){
        return a.second>b.second;
    }
    return a.first>b.first;
}

pair<int,int> arr[10001];
int schedule[10001];
int mxtime=0;
//d일 안에와서.. 즉 d일까지만 와서 하면 됌 0~d일 중에 한번
//1일부터 시작
/*
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        mxtime=max(mxtime,arr[i].second);
    }
    sort(arr,arr+n,comp);
    for(int i=0;i<n;i++){
        int idx=arr[i].second;
        int cost=arr[i].first;
        while(idx>0){
            if(schedule[idx]==0){
                schedule[idx]=cost;
                break;
            }
            else if(schedule[idx]<cost){
                int tmp=schedule[idx];
                schedule[idx]=cost;
                cost=tmp;
            }
            idx-=1;
        }
    }
    for(int i=1;i<=mxtime;i++){
        sum+=schedule[i];
    }
    cout<<sum;
    return 0;
}
*/

/*
그냥 입력받을때부터 넣으면 안되나..?
ㄴ 최대값부터 넣는게 효율적이지 않을까
ㄴ 그냥입력받을때부터 넣는게 빠르네
*/
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        mxtime=max(mxtime,arr[i].second);
        int idx=arr[i].second;
        int cost=arr[i].first;
        while(idx>0){
            if(schedule[idx]==0){
                schedule[idx]=cost;
                break;
            }
            else if(schedule[idx]<cost){
                int tmp=schedule[idx];
                schedule[idx]=cost;
                cost=tmp;
            }
            idx-=1;
        }
    }
    for(int i=1;i<=mxtime;i++){
        sum+=schedule[i];
    }
    cout<<sum;
    return 0;
}
/*
*/