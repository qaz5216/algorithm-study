#include <iostream>

using namespace std;

long long dp[101];

long long P(int n)
{
    if(dp[n])
    return dp[n];
    
    return dp[n]=P(n-3)+P(n-2);
}

int main()
{
    int T;
    cin >> T;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<P(n)<<"\n";
    }
    return 0;
}