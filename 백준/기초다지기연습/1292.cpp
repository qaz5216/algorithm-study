#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;

int sum(int n){
    int result=0;
    for(int i=1;i<=n;i++){
        result=result+i;
    }
    return result;
}

int main()
{
    int a,b,min,max,result=0;
    cin >> a>>b;
    for(int i=1;i<=b;i++){
        if(sum(i)>=a){
            min=i;
            break;
        }
    }
    for(int i=min;i<=b;i++){
        if(sum(i)>=b){
            max=i;
            break;
        }
    }
    if(min==max){
        result+=(b-a+1)*min;
    }
    else{
    for(int i=min;i<=max;i++){
        if(i==min){
            result+=(sum(min)-a+1)*i;
        }
        else if(i==max){
            result+=(max-(sum(max)-b))*i;
        }
        else {
            result+=i*i;
        }
    }
    }
    cout << result;
    return 0;
}
/*
1234  5 6 7 8910
13610 152128
122333444455555666666
*/