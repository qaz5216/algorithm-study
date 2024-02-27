#include <string>
#include <vector>
#include <math.h>
using namespace std;
int N;
string change(int num){
    string tmp="";
    int n=N-1;
    while(n){
        if(num>=pow(2,n)){
            tmp+='1';
            num=num-pow(2,n);
        }
        else{
            tmp+='0';
        }
        n--;
    }
    if(num==1)
        tmp+='1';
    else
        tmp+='0';
    return tmp;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    N=n;
    for(int i=0;i<n;i++){
        string tmp1;
        string tmp2;
        tmp1=change(arr1[i]);
        tmp2=change(arr2[i]);
        string tmp="";
        for(int i=0; i<n;i++){
            if(tmp1[i]=='1'||tmp2[i]=='1')
                tmp+='#';
            else
                tmp+=' ';
        }
        answer.push_back(tmp);
    }
    return answer;
}