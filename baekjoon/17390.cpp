#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, Q;
vector<int> arr;
int dp[300001];
vector<int> ans;

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dp[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1] + arr[i];
    }
    for (int i = 0; i < Q; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1)
            ans.push_back(dp[b - 1]);
        else
            ans.push_back(dp[b - 1] - dp[a - 2]);
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}