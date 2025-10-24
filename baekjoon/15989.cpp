#include <iostream>

using namespace std;

int n;
int dp3[10001];
int dp2[10001];
int dp1[10001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp1[1]=1;
    dp1[2]=1;
    dp2[2]=1;
    dp1[3]=2;
    dp3[3]=1;
    for(int i=4;i<=10000;i++){
        dp1[i]=dp1[i-1]+dp2[i-1]+dp3[i-1];//1로끝난거
        dp2[i]=dp2[i-2]+dp3[i-2];//2로끝난거
        dp3[i]=dp3[i-3];//3으로 끝난거
    }
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<dp1[n]+dp2[n]+dp3[n]<<'\n';
    }
    return 0;
}
/*


*/