#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n;

ll arr[100001];

vector<ll> ans;

ll cal(int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int l = mid;
    int r = mid + 1;
    ll result = max(cal(start, mid), cal(mid + 1, end));
    ll h = min(arr[l], arr[r]);

    result = max(result, h * (r - l + 1));

    while (start < l || r < end)
    {
        if (start == l)
            h = min(h, arr[++r]);
        else if (r == end)
            h = min(h, arr[--l]);
        else if (arr[l - 1] > arr[r + 1])
            h = min(h, arr[--l]);
        else
            h = min(h, arr[++r]);
        result = max(result, h * (r - l + 1));
    }
    return result;
}

void solve()
{
    ans.push_back(cal(0, n - 1));
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            for (ll answer : ans)
            {
                cout << answer << "\n";
            }
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        solve();
    }
    return 0;
}