#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            if (i == j)
            {
                dp[i] = max(1, dp[i]);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, dp[i]);
    }
    cout << result;
    return 0;
}