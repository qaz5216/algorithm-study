#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c, ans = 0;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int l = 1;
    int r = arr[n - 1] - arr[0];
    while (l <= r)
    {
        int router = 1;
        int mid = (l + r) / 2;
        int st = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - st >= mid)
            {
                router++;
                st = arr[i];
            }
        }
        if (router >= c)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
