#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1001] = {0,};


int main()
{
    int n;
    long long result;
    cin >> n;
    record[1]=1;
    record[2]=2;
    for (int i=3;i<=n;i++){
        record[i]=(record[i-2]+record[i-1])%10007;
    }
    cout << record[n];
    return 0;
}
/*
1=(1) 1
2=(1+1),(2) 2
F3=(1+1+1),(1+2) 1+2c1
F4=(1+1+1+1)(1+2+1)(2+2) 1+3c2+1
F5=(1+1+1+1+1)(2+1+1+1)(2+2+1) 1+4c3+3c1
F6=(1+1+1+1+1+1)(2+1+1+1+1)(2+2+1+1)(2+2+2) 1+5c4+4c2+1
F7=(1+1+1+1+1+1+1)(2+1+1+1+1+1)(2+2+1+1+1)(2+2+2+1) 1+6c5+5c3+4c1
F8=(1+1+1+1+1+1+1+1)(2+1+1+1+1+1+1)(2+2+1+1+1+1)(2+2+2+1+1)(2+2+2+2) 1+7c6+6c4+5c2+1
*/