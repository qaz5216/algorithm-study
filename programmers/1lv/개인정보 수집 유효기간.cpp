#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string,int> m;

int parse(string date){
    int sum=0;
    string yy,mm,dd;
    yy=date.substr(2,2);
    mm=date.substr(5,2);
    dd=date.substr(8,2);
    sum+=stoi(yy)*336;
    sum+=stoi(mm)*28;
    sum+=stoi(dd);
    return sum;
}


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    for(string s : terms){
        stringstream ss(s);
        string key,value,tmp;
        bool flag=true;
        while(ss>>tmp){
            if(flag){
                key=tmp;
                flag=false;
            }
            value=tmp;
        }
        m[key]=stoi(value)*28;
    }
    int now=parse(today);
    int idx=1;
    for(string s : privacies){
        int tmp=parse(s.substr(0,10));
        if(now-tmp>=m[s.substr(11,1)]){
            answer.push_back(idx);
        }
        idx++;
    }
    return answer;
}

/*
28*12=280+56=336
1년:336

*/