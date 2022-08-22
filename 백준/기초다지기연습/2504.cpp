#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
string arr;
vector <string> check;


int main()
{
    cin >> arr;
    int result=1;
    for(int i=0;i<arr.length();i++){
        if(arr[i]=='('){
            string tmp="";
            check.push_back("(");
        }
        else if(arr[i]==')'){
            if(check.size()==0){
                cout << 0;
                return 0;
            }
            if(check.back()!="("){
                cout << 0;
                return 0;
            }
            check.pop_back();
        }
        else if(arr[i]=='['){
            check.push_back("[");
        }
        else if(arr[i]==']'){
            if(check.size()==0){
                cout << 0;
                return 0;
            }
             if(check.back()!="["){
                cout << 0;
                return 0;
            }
            check.pop_back();
        }
        else{
            cout<<0;
            return 0;
        }
    }
    if(check.size()!=0){
        cout << 0;
        return 0;
    }
    //계산시작
      for(int i=0;i<arr.length();i++){
        if(arr[i]=='('){
            check.push_back("(");
        }
        else if(arr[i]==')'){
           if (check.back()!="("){
                string tmp=check.back();
                int find =1;
                check.pop_back();
                while(find){
                    if(check.back()!="("){
                        tmp=to_string(stoi(tmp)+stoi(check.back()));
                        check.pop_back();
                    }
                    else{
                        tmp=to_string(stoi(tmp)*2);
                        check.pop_back();
                        find=0;
                    }
                }
                check.push_back(tmp);
            }
            else{
            check.pop_back();
            check.push_back("2");
            }// 8  
        }
        else if(arr[i]=='['){
            check.push_back("[");
        }
        else if(arr[i]==']'){
             if(check.back()!="["){
                string tmp=check.back();
                int find =1;
                check.pop_back();
                while(find){
                    if(check.back()!="["){
                        tmp=to_string(stoi(tmp)+stoi(check.back()));
                        check.pop_back();
                    }
                    else{
                        tmp=to_string(stoi(tmp)*3);
                        check.pop_back();
                        find=0;
                    }
                }
                check.push_back(tmp);
            }
            else{
            check.pop_back();
            check.push_back("3");
            }
        }
        else{
        }
    }
    while(check.size()>1){
       string tmp=check.back();
       check.pop_back();
       tmp=to_string(stoi(tmp)+stoi(check.back()));
       check.pop_back();
       check.push_back(tmp); 
    }
    if(check.size()>=1){
    cout << check.back();
    }
    return 0;
}