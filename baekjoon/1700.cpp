#include <iostream>
#include <queue>

using namespace std;

int con[101]; //콘센트에 꽂혀있는 기계 0: 안꽂혀있음
int ntime[101]; //콘센트에 꽂혀있는 기계의 다음 사용시간
int dp[101]; //기계의 콘센트 위치 0 : 안꽂혀있음
int arr[101];
int sum=0;
int n,k;
priority_queue<int,vector<int>,greater<int>> pq[101];

void connect(int x)
{
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        cin>>arr[i];
        pq[arr[i]].push(i);
    }
    for(int i=1;i<=n;i++)
    {
        ntime[i]=102; // 모든콘센트 비어있음
    }
    for(int i=1;i<=k;i++)
    {
        if(dp[arr[i]]!=0) //이미 꽂혀있다면
        {
            if(!pq[arr[i]].empty()){ //기계가 다음에도 사용되면
            ntime[dp[arr[i]]]=pq[arr[i]].top();pq[arr[i]].pop();
            }
            else{
            ntime[dp[arr[i]]]=101;
            }
        }
        else    //안꽂혀있으면
        {   
            int idx=1;
            for(int i=2;i<=n;i++)
            {
                if(ntime[idx]<ntime[i])
                {
                    idx=i;
                }
            }
            // 콘센트 빼기
            dp[con[idx]]=0; //빼기
            con[idx]=arr[i]; //꼽기
            dp[arr[i]]=idx; //꼽기
            if(pq[arr[i]].top()==i) {
                if(!pq[arr[i]].empty()){
                    pq[arr[i]].pop();
                }
            }
            if(!pq[arr[i]].empty()){ //기계가 다음에도 사용되면
                ntime[dp[arr[i]]]=pq[arr[i]].top();pq[arr[i]].pop();
            }
            else{
                ntime[dp[arr[i]]]=101;
            }
            sum+=1;
        }
    }
    cout<<max(0,sum-n);//멀티탭이 가전제품보다 많은경우 0
    return 0;
}
