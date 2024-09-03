#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][51];
const int INF=1e9;


int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = 0;
    temperature += 10;
    t1 += 10;
    t2 += 10;
    for(int i=0;i<1001;i++)
    {
        for(int j=0;j<51;j++)
        {
            dp[i][j]=INF;
        }
    }
    dp[0][temperature]=0;
    for(int i=0;i<onboard.size()-1;i++)
    {
        for(int j=0;j<=50;j++)
        {
            if(onboard[i]&&(j<t1||t2<j)) continue;
            int temp=j;
            if(j<temperature&&j<50)
            {
                temp++;
            }
            else if(j>temperature&&j>0)
            {
                temp--;
            }
            //에어컨을 안켰을때
            dp[i+1][temp]=min(dp[i+1][temp],dp[i][j]);
            //에어컨 켰을때
            if(j>0) //온도를 내릴때
            {
                dp[i+1][j-1]=min(dp[i+1][j-1],a+dp[i][j]);
            }
            if(j<50) //온도를 올릴때
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],a+dp[i][j]);
            }
            //온도 유지시킬때
            dp[i+1][j]=min(dp[i+1][j],b+dp[i][j]);
        }
    }
    answer=dp[onboard.size()-1][t1];
    for(int i=0;i<=50;i++)
    {
        if(onboard[onboard.size()-1]==1&&(i<t1||t2<i)) continue;
        answer=min(answer,dp[onboard.size()-1][i]);
    }
    return answer;
}