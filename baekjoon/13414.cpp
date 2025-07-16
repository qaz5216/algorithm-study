#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

int k, l;
unordered_map<string, bool> m;
string arr[500001];
stack<string> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> arr[i];
    }
    for (int i = l - 1; i >= 0; i--)
    {
        if (m[arr[i]])
            continue;
        m[arr[i]] = true;
        s.push(arr[i]);
    }
    while (!s.empty() && k--)
    {
        string stuid = s.top();
        s.pop();
        cout << stuid << '\n';
    }
    return 0;
}