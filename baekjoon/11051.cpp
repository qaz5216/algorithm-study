#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ncr[1001][1001] = {
    0,
};
int main()
{
    int n, k, result = 1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        ncr[i][1] = i;
        ncr[i][i] = 1;
        ncr[i][0] = 1;
    }
    for (int i = 3; i <= n; i++)
        for (int j = 2; j < i; j++)
        {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % 10007;
        }

    cout << ncr[n][k];
    return 0;
}
