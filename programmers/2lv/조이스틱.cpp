#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
vector<int> arr;
int ans;
void solve(){
    int move=arr.size()-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            ans+=arr[i];
        }
        int nmove=i+1;
        while(nmove<arr.size()&&arr[nmove]==0)
            nmove++;
        int nnmove=min(2*i+(arr.size()-nmove),2*(arr.size()-nmove)+i);
        move=min(move,nnmove);
    }
    ans+=move;
}

int solution(string name) {
    int answer = 0;
    for(int i=0;i<name.size();i++){
        int tmp=name[i]-'A';
        if(tmp>13){
        arr.push_back(abs(tmp-26));
        }
        else{
        arr.push_back(tmp);
        }
    }
    ans=0;
    solve();
    answer=ans;
    return answer;
}