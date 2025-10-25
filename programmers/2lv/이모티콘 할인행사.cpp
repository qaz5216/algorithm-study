#include <string>
#include <vector>

using namespace std;

pair<int,int> ans;
int n;
int discount[7];
vector<vector<int>> userss;
vector<int> emoticonss;
void calc(){
    int cnt=0;
    int sum=0;
    for(vector<int> user:userss){
        int tmp=0;
        int cut=user[0];
        int subscribe=user[1];
        for(int i=0;i<n;i++){
            if(discount[i]>=cut){
                tmp+=(100-discount[i])*emoticonss[i];
            }
            if(tmp>=subscribe){
                cnt++;
                tmp=0;
                break;
            }
        }
        sum+=tmp;
    }
    ans=max(ans,{cnt,sum});
}
void comb(int cur){
    if(cur==n){
        calc();
        return;
    }
    for(int i=1;i<=4;i++){
        discount[cur]=i*10;
        comb(cur+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    n=emoticons.size();
    userss=std::move(users);
    emoticonss=std::move(emoticons);
    for(int i=0;i<n;i++){
        emoticonss[i]/=100;
    }
    ans={0,0};
    comb(0);
    answer.push_back(ans.first);
    answer.push_back(ans.second);
    return answer;
}

/*
40^7승..? 빡구현x
할인율 10단위네..
4^7승 빡구현..

*/