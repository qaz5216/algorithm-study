#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int alp[26];

int main()
{
    string s;
    string ans;
    cin >> s;
    int check = 0;
    int idx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        alp[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (alp[i] % 2 == 1)
        {
            check++;
            idx = i;
        }
    }
    if (check > 1)
    {
        cout << "I'm Sorry Hansoo";
        return 0;
    }

    else
    {
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < alp[i] / 2; j++)
            {
                ans.push_back(('A' + i));
            }
        }
    }
    string tmp = ans;
    reverse(tmp.begin(), tmp.end());
    if (idx != -1)
    {
        ans.push_back('A' + idx);
    }
    ans += tmp;
    cout << ans;
    return 0;
}