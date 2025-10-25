#include <iostream>
#include <algorithm>
using namespace std;

<<<<<<< HEAD:백준/15655.cpp
int n,m;
=======
int n, m;
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/15655.cpp
int ans[8];
int arr[8];
bool visit[8];

<<<<<<< HEAD:백준/15655.cpp
void comb(int x,int idx){ //idx=for문시작위치
    if(x==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=idx;i<n;i++){
        if(visit[i])continue;
        visit[i]=true;
        ans[x]=arr[i];
        comb(x+1,i+1);//지금넣은거보다 큰거부터시작해
        visit[i]=false;
=======
void comb(int x, int idx)
{ // 오름차순 조합뽑기
    if (x == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < n; i++)
    { // 시작 idx부터
        if (visit[i])
            continue;
        visit[i] = true;
        ans[x] = arr[i];
        comb(x + 1, i + 1); // i+1부터 다음꺼 시작
        visit[i] = false;
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/15655.cpp
    }
}

int main()
{
<<<<<<< HEAD:백준/15655.cpp
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);//정렬
    comb(0,0);
=======
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n); // 정렬
    comb(0, 0);
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/15655.cpp
    return 0;
}