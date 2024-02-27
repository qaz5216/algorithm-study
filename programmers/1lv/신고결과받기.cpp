#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n=id_list.size();
    int police[1001];
    memset(police,0,sizeof(police));
    vector<int> num[1001];
    for(int i=0;i<report.size();i++){
        string tmp1="";
        bool check=true;
        string tmp2="";
        for(int j=0;j<report[i].size();j++){
            if(report[i][j]==' '){
                check=false;
                continue;
            }
            if(check){
                tmp1+=report[i][j];
            }
            else{
                tmp2+=report[i][j];
            }
        }
        int idx1;
        int idx2;
        for(int j=0;j<n;j++){
            if(id_list[j]==tmp1)
                idx1=j;
            if(id_list[j]==tmp2)
                idx2=j;
        }
        int twice=0;
        for(int j=0;j<num[idx2].size();j++){
            if(num[idx2][j]==idx1){
                twice=1;
                break;
            }
        }
        if(twice==0)
            num[idx2].push_back(idx1);
    }
    for(int i=0;i<n;i++){
        if(k<=num[i].size()){
            for(int j=0;j<num[i].size();j++){
                police[num[i][j]]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        answer.push_back(police[i]);
    }
    
    return answer;
}