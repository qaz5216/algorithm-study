#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> h;
    vector<int> j;
    int ans = 1;
    for (int i = 0; i < 3; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 0)
        {
            j.push_back(x);
        }
        else
        {
            h.push_back(x);
        }
    }
    if (h.size() == 0)
    {
        for (int x : j)
        {
            ans *= x;
        }
    }
    else
    {
        for (int x : h)
        {
            ans *= x;
        }
    }
    cout << ans;
    return 0;
}