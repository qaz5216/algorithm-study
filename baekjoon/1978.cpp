#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;

int main()
{
    int t,tmp,result=0;
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> tmp;
        arr.push_back(tmp);
    }
    int check=0;
    for(int i=0;i<arr.size();i++){
        check=0;
        if(arr[i]==1)
        check=1;
        for(int j=2;j<arr[i];j++){
            if(arr[i]%j==0)
            check=1;
        }
        if(check==0){
            result++;
        }
    }
    cout << result;
    return 0;
}