#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a,vector<int> b)
{
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<int>> intbook;
    for(auto time:book_time){
        vector<int> tmp;
        int min=0;
        string hh=time[0].substr(0,2);
        string mm=time[0].substr(3,2);
        min=60*stoi(hh)+stoi(mm);
        tmp.push_back(min);
        hh=time[1].substr(0,2);
        mm=time[1].substr(3,2);
        min=60*stoi(hh)+stoi(mm);
        tmp.push_back(min);
        intbook.push_back(tmp);
    }
    sort(intbook.begin(),intbook.end(),cmp);
    vector<int> room;
    for(auto time:intbook){
        vector<int> tmp;
        for(auto rm:room){
            if(rm>time[0])
                tmp.push_back(rm);
        }
        tmp.push_back(time[1]+10);
        room=tmp;
        if(answer<room.size())
            answer=room.size();
    }
    return answer;
}