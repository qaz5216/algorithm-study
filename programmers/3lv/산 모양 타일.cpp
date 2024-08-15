#include <string>
#include <vector>

using namespace std;

int dp1[100001];
int dp2[100001];

int solution(int n, vector<int> tops) {
    int answer = 0;
    dp1[0]=1;
    for(int i=0;i<tops.size();i++)
    {
        if(tops[i]==1){
            dp1[i+1]=3*dp1[i]+2*dp2[i];
            dp2[i+1]=dp1[i]+dp2[i];
            
        }
        else{
            dp1[i+1]=2*dp1[i]+dp2[i];
            dp2[i+1]=dp1[i]+dp2[i];
        }
        dp1[i+1]=dp1[i+1]%10007;
        dp2[i+1]=dp2[i+1]%10007;
    }
    answer=dp1[n]+dp2[n];
    return answer%10007;
}

/*
    dp1[n]=삼각형으로 끝난경우
    dp2[n]=오른마름모로 끝난경우

    no top
    dp1[1]=2
    dp2[1]=1

    exist top
    dp1[1]=3
    dp2[1]=1

    no top
    dp1[2]=5=2*dp1[1]+dp2[1]
    dp2[2]=3=dp[1]+dp[2]
    
    exist top
    dp1[2]=8=3*dp1[1]+2*dp2[1]
    dp2[2]=3=dp1[1]+dp1[2]
    
    no top
    dp1[n]=2*dp1[n-1]+dp2[n-1];
    dp2[n]=dp1[n-1]+dp2[n-1];
    
    exist top
    dp1[n]=3*dp1[n-1]+2*dp2[n-1];
    dp2[n]=dp1[n-1]+dp1[n-1];
    
    예제1) n=4 tops{1,1,0,1}
    dp1[0]=1;
    dp2[0]=0;
    dp1[1]=3;
    dp2[1]=1;
    dp1[2]=11;
    dp2[2]=4;
    dp1[3]=26;
    dp2[3]=15;
    dp1[4]=108;
    dp2[4]=41;
*/