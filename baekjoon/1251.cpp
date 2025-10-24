#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    string s, ans, tmp;
    cin >> s;
    tmp = s;
    reverse(tmp.begin(), tmp.begin() + 1);
    reverse(tmp.begin() + 1, tmp.begin() + 2);
    reverse(tmp.begin() + 2, tmp.end());
    ans = tmp;
    for (int i = 0; i < s.size() - 2; i++)
    {
        for (int j = i + 1; j < s.size() - 1; j++)
        {
            tmp = s;
            reverse(tmp.begin(), tmp.begin() + i + 1);
            reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
            reverse(tmp.begin() + j + 1, tmp.end());
            if (ans > tmp)
            {
                ans = tmp;
            }
        }
    }
    cout << ans;
    return 0;
}