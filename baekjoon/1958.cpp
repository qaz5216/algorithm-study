#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[101][101][101];

int main()
{
    
    string str1,str2,str3;
    cin >> str1 >> str2 >> str3;
    int result=0;
    for(int i=0;i<str1.length();i++){
        for(int j=0;j<str2.length();j++){
            for(int k=0;k<str3.length();k++){
            if(str1[i]==str2[j]&&str1[i]==str3[k]){
                arr[i+1][j+1][k+1]=arr[i][j][k]+1;
                if(result<arr[i][j][k]+1)
                result=arr[i][j][k]+1;
            }
            else{
                arr[i+1][j+1][k+1]= max(max(arr[i][j+1][k+1],arr[i+1][j][k+1]),arr[i+1][j+1][k]);
            }        
            }
        }
    }
    cout << result;
    return 0;
}