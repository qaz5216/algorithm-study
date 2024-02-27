#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> tmp;
    int n=survey.size();
    for(int i=0;i<n;i++){
        if(choices[i]<4){
            tmp[survey[i][0]]+=4-choices[i];
        }
        else if(choices[i]>4){
            tmp[survey[i][1]]+=choices[i]-4;
        }
    }
    if(tmp['R']>=tmp['T'])
        answer+='R';
    else
        answer+='T';
    if(tmp['C']>=tmp['F'])
        answer+='C';
    else
        answer+='F';
    if(tmp['J']>=tmp['M'])
        answer+='J';
    else
        answer+='M';
    if(tmp['A']>=tmp['N'])
        answer+='A';
    else
        answer+='N';
    
    return answer;
}