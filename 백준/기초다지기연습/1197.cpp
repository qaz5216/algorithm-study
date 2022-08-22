#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
vector <string> arr;
int answer;
int check[26]={0};

int read(){
    int num=0;
    int can=1;
    for(int i=0;i<arr.size();i++){
        can=1;
        for(int j=0;j<arr[i].length();j++){
            if(check[arr[i][j]-'a']==0){
                    can=0;
                    break;
            }
        }
        if(can==1)
        num++;
    }
    return num;
}

void DFS(int idx ,int start ,int end){    //깊이탐색(조합)
   if (start == end) {
        int dfsresult=read();
        answer = max(answer, dfsresult);
        return;
    }
    for (int i = idx; i<26;i++) {
        if (check[i]==1)
            continue;
        check[i] = 1;
        DFS(i, start+1,end);
        check[i] = 0;
    }
}

int main()
{
    int t,k,tmp;
    cin >> t >> k;
    
    for(int i=0;i<t;i++){
        string tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    if(k<5){
        cout << 0;
        return 0;
    }
    check['t'-'a']=1;
    check['i'-'a']=1;
    check['c'-'a']=1;
    check['n'-'a']=1;
    check['a'-'a']=1;
    DFS(0,0,k-5);
    cout << answer;
    return 0;
}