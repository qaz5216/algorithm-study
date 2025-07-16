#include <iostream>

using namespace std;

int n, m;
int ans = 1e9;
int arr[100001];

int main()
{
    cin >> n >> m;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int l = mx;
    int r = 1e9;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int b = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                b++;
                sum = arr[i];
            }
        }
        if (b <= m)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}