#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[4001][4001];

int main()
{
    
    string str1,str2;
    cin >> str1 >> str2;
    int result=0;
    for(int i=0;i<str1.length();i++){
        for(int j=0;j<str2.length();j++){
            if(str1[i]==str2[j]){
                arr[i+1][j+1]=arr[i][j]+1;
                if(result<arr[i][j]+1)
                result=arr[i][j]+1;
            }
        }
    }
    cout << result;
    return 0;
}

