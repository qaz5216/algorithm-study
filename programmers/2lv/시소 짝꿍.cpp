#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int,long long> mp;
    bool visit[1001][1001];
    memset(visit,true,sizeof(visit));
    for(int w:weights){
        mp[w]++;
    }
    sort(weights.begin(),weights.end());
    vector<int> list;
    for(int w:weights){
        if(list.size()==0)
            list.push_back(w);
        else{
            if(list[list.size()-1]!=w)
                list.push_back(w);
        }
    }
    for(int w:list){
        if(visit[w][w]){
            answer+=(mp[w]*(mp[w]-1))/2;
            visit[w][w]=false;
        }
        for(int i=2;i<5;i++){
            for(int j=2;j<5;j++){
                if(i!=j&&(w*i)%j==0)
                {
                    if(w*i/j<=1000)
                    if(visit[w][w*i/j]&&mp[w*i/j]!=0){
                        visit[w][w*i/j]=false;
                        visit[w*i/j][w]=false;
                        answer+=mp[w]*mp[w*i/j];
                   }
                }
            }
        }
    }
    return answer;
}