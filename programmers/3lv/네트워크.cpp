#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int cnt;
int check[200];
void dfs(int idx,int check[],vector<vector<int>> computers)
{
    check[idx]=1;
    for(int i=0;i<computers.size();i++){
        if(i!=idx){
            if(computers[idx][i]==1&&check[i]==0){
                dfs(i,check,computers);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    cnt=0;
    memset(check,0,sizeof(check));
    for(int i=0;i<n;i++){
        if(check[i]==0){
            cnt++;
            dfs(i,check,computers);
        }
    }
    return cnt;
}