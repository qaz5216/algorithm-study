#include <iostream>
#include <algorithm>

using namespace std;

int n,c;
int arr[200001];
int INF=1e9+1;

int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int l=0;
    int r=INF;
    while(l<r){
        int mid=(l+r)/2;
        int cnt=1;
        int pre=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-pre>=mid){
                cnt++;
                pre=arr[i];
            }
        }
        //upperbound
        if(cnt<c)//c보다 덜심었으면 거리줄이기
        {
            r=mid;
        }
        else{//더심었거나 거리같으면 늘리기
            l=mid+1;
        }
    }
    cout<<r-1;
    return 0;
}

/*
n=20만

n log(n)
n개인데 각자 자기위치 찾는데 log(n);
어처피 처음껀 무조건 심겠네?
거리가 10억인데.. 거리를 이분탐색..?
점부터 정렬하고
c개 심을수 있는 최대거리 upperbound
mid 로 몇개심을수 있는지 검사하기

*/