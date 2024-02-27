#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(pair<string,int> A,pair<string,int> B){
    return A.second>B.second;
}
bool cmp2(pair<pair<string,int>,int> A,pair<pair<string,int>,int> B){
    return A.first.second>B.first.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<pair<string,int>,int>> list;
    map<string,int> gen;
    for(int i=0;i<genres.size();i++){
        list.push_back(make_pair(make_pair(genres[i],plays[i]),i));
        gen[genres[i]]+=plays[i];
    }
    vector<pair<string,int>> vec( gen.begin(), gen.end() );
    sort(vec.begin(),vec.end(),cmp);
    sort(list.begin(),list.end(),cmp2);
    for(auto v:vec){
        int i=0;
        for(auto check:list){
            if(i==2)
                break;
            if(v.first==check.first.first){
                answer.push_back(check.second);
                i++;
            }
        }
    }
    return answer;
}