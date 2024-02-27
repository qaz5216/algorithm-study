#include <string>
#include <vector>

using namespace std;
bool map[100][100]={};
long long  dp[100][100]={};
int dx[2]={1,0};
int dy[2]={0,1};
int M,N;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    M=m;
    N=n;
    for(int i=0;i<m;i++){
    dp[i][0]=1;
    }
    for(int i=0;i<n;i++){
    dp[0][i]=1;
    }
    for(auto puddle:puddles){
        dp[puddle[0]-1][puddle[1]-1]=0;
        map[puddle[0]-1][puddle[1]-1]=1;
        if(puddle[0]-1==0){
            for(int i=puddle[1]-1;i<n;i++){
                dp[0][i]=0;
                map[0][i]=1;
            }
        }
        if(puddle[1]-1==0){
            for(int i=puddle[0]-1;i<m;i++){
                dp[i][0]=0;
                map[i][0]=1;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(map[i][j]==0){    
                    dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            }
        }
    }
    return dp[m-1][n-1];
}