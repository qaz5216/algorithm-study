#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int price[10];
vector<pair<int, int>> arr;
char ans[51];

int main()
{
    int n, m;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
        arr.push_back({price[i], i});
    }
    cin >> m;
    if(n==1){
        cout<<0;
        return 0;
    }
    sort(arr.begin(), arr.end());
    int k = m / arr[0].first; // 싼걸로 다산거
    m = m % arr[0].first;     // 남은돈
    if (k!=1&&arr[0].second == 0)
    { // 제일싼게 0이었으면 자리수 하나는 바꿔봐야지
        int cnt=0;
        m+=arr[0].first;
        while(m<arr[1].first){
            m+=arr[0].first;
            cnt++;
        }
        k-=cnt;
        if(k<=0){
            cout<<0;
            return 0;
        }
        //돈채우자
        //돈빼자
        m-=arr[1].first;
        ans[0] = '0'+arr[1].second;
        for (int i = 1; i < k; i++)
        {
            ans[i] = '0'+arr[0].second;
        }
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            ans[i] = '0'+arr[0].second;
        }
    }
    //자리수는 정해졌고 이제 자리 번호 높은걸로 바꿀수있는지 보자
    for(int i=0;i<k;i++){
        int cur=ans[i]-'0';
        if(cur==n-1)continue;
        for(int j=n-1;j>cur;j--){
            if(m+price[cur]>=price[j]){
                ans[i]='0'+j;
                m+=price[cur]-price[j];
                break;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cout << ans[i];
    }
    return 0;
}

/*
0으로 다사는경우가 아니라면 많이사는게 일단 큼
제일싼걸로 다사고
그 개수만큼 살수있는만큼
높은자리수부터 제일큰수로 채워보기
최대 50자리임

!적어도 하나는 살수있게 주어짐
!방 번호가 0이 아니라면 0으로 시작할 수 없다.

1
 3 5
n*3>=6/3

n*3>=5-1

n>4/3
m+n*arr[0]>=arr[1];
n>=(arr[1]-m)/arr[0];
10000000000000
10000000000000
22222222222222222222222222222222222222222222222222
22222222222222222222222222222222222222222222222222 


99888888
50000000
*/