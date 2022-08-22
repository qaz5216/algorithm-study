#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1000001];

int fib(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else{
        return fib(n-2)+fib(n-1);
    }

}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}