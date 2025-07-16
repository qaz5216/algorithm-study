#include <iostream>
#include <vector>
using namespace std;

string S;
int q;

int dp[26][200001];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S;
    cin >> q;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (i == 0)
            {
                if (S[i] - 'a' == j)
                {
                    dp[j][i] = 1;
                }
                else
                {
                    dp[j][i] = 0;
                }
            }
            else
            {
                if (S[i] - 'a' == j)
                {
                    dp[j][i] = dp[j][i - 1] + 1;
                }
                else
                {
                    dp[j][i] = dp[j][i - 1];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        char tmp;
        int a, b;
        cin >> tmp >> a >> b;
        if (a == 0)
        {
            ans.push_back(dp[tmp - 'a'][b]);
        }
        else
        {
            ans.push_back(dp[tmp - 'a'][b] - dp[tmp - 'a'][a - 1]);
        }
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }

    return 0;
}