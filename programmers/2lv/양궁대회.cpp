#include <string>
#include <vector>

using namespace std;
vector<int> INFO;
vector<int> answer;
int mx;

void calc(vector<int> ryon){
    int appeach=0;
    int score=0;
    for(int i=0;i<11;i++){
        if(!(INFO[i]==0&&ryon[i]==0)){
           if(INFO[i]>=ryon[i]){
               appeach+=(10-i);
           }
            else{
                score+=(10-i);
            }
        }
    }
    
    if(mx<=score-appeach){
        if(mx==score-appeach&&mx!=0){
            for(int i=10;i>0;i--){
                if(answer[i]!=0||ryon[i]!=0){
                    if(answer[i]!=0)
                        return;
                    else{
                        answer=ryon;
                        return;
                    }
                }
            }
        }
        else{
            if(score-appeach==0)
                return;
            mx=score-appeach;
            answer=ryon;
            return;
        }
    }
    return;
}

void dfs(int cnt,int n,vector<int> ryon){
    if(cnt==11||n==0){
        ryon[10]+=n;
        calc(ryon);
        ryon[10]-=n;
    }
    else{
        if(n>INFO[cnt]){
            ryon[cnt]=INFO[cnt]+1;
            dfs(cnt+1,n-INFO[cnt]-1,ryon);
            ryon[cnt]=0;
        }
        dfs(cnt+1,n,ryon);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryon(11,0);
    INFO=info;
    mx=0;
    dfs(0,n,ryon);
    if(mx<=0){
        answer.push_back(-1);
    }
    return answer;
}