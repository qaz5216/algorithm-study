#include <iostream>
#include <vector>
using namespace std;

int N, Q, U, V;

int arr[1001];
int dp[1001];
vector<int> ans;
int querymax(int a, int b)
{
    dp[a - 1] = arr[a - 1] * U;
    int result = dp[a - 1];
    for (int i = a; i < b; i++)
    {
        dp[i] = max(dp[i - 1] + arr[i] * U + V, arr[i] * U);
        result = max(result, dp[i]);
    }
    return result;
}

int main()
{
    cin >> N >> Q >> U >> V;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < Q; i++)
    {
        int c, a, b;
        cin >> c >> a >> b;
        if (c == 0)
        {

            ans.push_back(querymax(a, b));
        }
        else
        {
            arr[a - 1] = b;
        }
    }

    for (int answer : ans)
    {
        cout << answer << "\n";
    }

    return 0;
}