#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;

string v[20001];
map<string, bool> m;

bool comp(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return a[i] < b[i];
        }
    }
    return true;
}

bool lencomp(string a, string b)
{
    if (a.length() == b.length())
    { // 길이가 같으면
        return comp(a, b);
    }
    return a.length() < b.length();
}

int main()
{
    int dup = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (m[s])
        { // 중복체크
            dup++;
        }
        else
        {
            v[i - dup] = s; // i-중복된거나온만큼 빼고
            m[s] = true;
        }
    }
    n -= dup;
    sort(v, v + n, lencomp);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}