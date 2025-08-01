#include <iostream>

using namespace std;

int dp0[41];
int dp1[41];

int main()
{
    int t;
    cin >> t;
    dp0[0] = 1;
    dp1[0] = 0;
    dp0[1] = 0;
    dp1[1] = 1;
    for (int i = 2; i <= 40; i++)
    {
        dp0[i] = dp0[i - 2] + dp0[i - 1];
        dp1[i] = dp1[i - 2] + dp1[i - 1];
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp0[n] << " " << dp1[n] << "\n";
    }
    return 0;
}