#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i] * b[i];
    }
    cout << s;
    return 0;
}