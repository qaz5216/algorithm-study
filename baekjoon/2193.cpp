#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long record[92] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    record[1] = 1;
    record[2] = 1;
    for (int i = 3; i < n + 1; i++)
    {
        record[i] = record[i - 1] + record[i - 2];
    }
    cout << record[n];
    return 0;
}
/*
3=2
100
101
4=3
1000
1001
1010
5=5
10000
10001
10010
10100
10101
7=8
100000
100001
100010
100100
100101
101000
101001
101010
뒤가 0으로 끝난 개수만큼 증가함
0은 모든경우 붙일수 있음으로
뒤에 0으로 끝난 개수는 전전 레코드의 수임.
*/