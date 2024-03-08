#include <iostream>
#include <vector>

using namespace std;

int N,M;
int arr[100001];
int dp[100001];
vector <int> ans;

int cal(int a,int b)
{
    int result;
    if(a==0)
    result=dp[b];
    else
    result=dp[b]-dp[a-1];    
    return result;
}

int main()
{
    cin >> N >> M;
    for(int i=0;i<N;i++)
    {
        cin>> arr[i];
        if(i==0)
        dp[i]=arr[i];
        else
        dp[i]=dp[i-1]+arr[i];
    }
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>> a>>b;
        ans.push_back(cal(a-1,b-1));
    }
    for(int answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}