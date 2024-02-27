#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> map;
    for(auto cloth:clothes){
            map[cloth[1]]+=1;
    }
    for(auto i=map.begin();i!=map.end();i++){
        answer*=(*i).second+1;
    }
    
    
    return answer-1;
}