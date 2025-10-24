#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1001] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    record[1] = 1;
    record[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        record[i] = (2 * record[i - 2] + record[i - 1]) % 10007;
    }
    cout << record[n];
    return 0;
}