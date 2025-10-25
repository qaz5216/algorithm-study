#include <iostream>

using namespace std;

int arr[15];
<<<<<<< HEAD:백준/9663.cpp
int n,ans=0;

bool check(int x,int idx)
{
    for(int i=0;i<x;i++){
        if(arr[i]==idx)  //i번줄에서 이미 idx를 먹은경우
            return false;
        if(abs(x-i)==abs(idx-arr[i]))//대각선에 있는경우
=======
int n, ans = 0;

bool check(int x, int idx)
{
    for (int i = 0; i < x; i++)
    {
        if (arr[i] == idx) // i번줄에서 이미 idx를 먹은경우
            return false;
        if (abs(x - i) == abs(idx - arr[i])) // 대각선에 있는경우
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/9663.cpp
            return false;
    }
    return true;
}

<<<<<<< HEAD:백준/9663.cpp
void dfs(int x){
    if(x==n){
=======
void dfs(int x)
{
    if (x == n)
    {
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/9663.cpp
        ans++;
        return;
    }
    {
<<<<<<< HEAD:백준/9663.cpp
        for(int i=0;i<n;i++){
            if(check(x,i))
            {
                arr[x]=i; //넣을수있으면 넣어
                dfs(x+1);
=======
        for (int i = 0; i < n; i++)
        {
            if (check(x, i))
            {
                arr[x] = i; // 넣을수있으면 넣어
                dfs(x + 1);
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/9663.cpp
            }
        }
    }
}

int main()
{
<<<<<<< HEAD:백준/9663.cpp
    cin>>n;
    dfs(0);
    cout<<ans;
=======
    cin >> n;
    dfs(0);
    cout << ans;
>>>>>>> 8312378e13982975752a989a6676e73e80bad10c:baekjoon/9663.cpp
    return 0;
}