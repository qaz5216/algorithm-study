#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int i=1;i<=s.size()/2;i++){
        int n=1;
        string tmp="";
        string cmp;
        cmp=s.substr(0,i);
        for(int j=i;j<s.size();j+=i){
            if(cmp==s.substr(j,i))n++;
            else{
                if(n>1) tmp+=to_string(n);
                tmp+=cmp;
                cmp=s.substr(j,i);
                n=1;
            }
        }
        if(n>1)
            tmp+=to_string(n);
        tmp+=cmp;
        if(answer>tmp.size())
            answer=tmp.size();
    }
    return answer;
}