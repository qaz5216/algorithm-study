#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    if (a == b)
        return false;
    if (a + b >= b + a)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    bool zero = true;
    cin >> n;
    vector<int> v;
    vector<string> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a != 0)
            zero = false;
        v.push_back(a);
    }
    if (zero)
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        s.push_back(to_string(v[i]));
    }
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    return 0;
}