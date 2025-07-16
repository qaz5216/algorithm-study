#include <iostream>
#include <vector>
using namespace std;

int T;
int N;
int dp[1001];
vector<int> ans;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        cin >> dp[0];
        int result = dp[0];
        for (int i = 1; i < N; i++)
        {
            int tmp;
            cin >> tmp;
            dp[i] = max((dp[i - 1] + tmp), tmp);
            result = max(result, dp[i]);
        }
        ans.push_back(result);
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}