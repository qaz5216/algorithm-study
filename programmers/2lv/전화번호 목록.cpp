#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string,bool> map;
    for(auto ele:phone_book)
            map[ele]=true;
    for(auto ele:phone_book)
            for(int i=0;i<ele.size()-1;i++){
                string cmp=ele.substr(0,i+1);
                if(map[cmp]==true)
                    return false;
            }
    return true;
}