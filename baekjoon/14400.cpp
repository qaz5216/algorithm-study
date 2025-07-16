#include <iostream>
#include <algorithm>
using namespace std;

int n;

int arrx[100001];
int arry[100001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arrx[i] >> arry[i];
    }
    sort(arrx, arry + n);
    sort(arrx, arry + n);
    long long ans = 1e12;
    for (int i = 0; i < n; i++)
    {
    }
    return 0;
}

/*
9 13
2 3


6
10
15

31 x

*/