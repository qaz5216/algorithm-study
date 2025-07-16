#include <iostream>
#define ll long long
using namespace std;

int N;
int arr[5001];
ll dp[5001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < N; i++)
    {
        dp[i] = (ll)i * (1 + abs(arr[0] - arr[i]));
        for (int j = 1; j < i; j++)
        {
            dp[i] = min(max((ll)(i - j) * (1 + abs(arr[j] - arr[i])), dp[j]), dp[i]);
        }
    }
    cout << dp[N - 1];
    return 0;
}