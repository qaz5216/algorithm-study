#include <iostream>
#include <algorithm>
using namespace std;

int arr[52];

int main()
{
    int n, m, l;
    cin >> n >> m >> l;
    arr[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = l;
    sort(arr, arr + n + 2);
    int left = 1;
    int right = l;
    int ans = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            int dist = arr[i] - arr[i - 1];
            cnt += dist / mid;
            if (dist % mid == 0)
            {
                cnt--;
            }
        }
        if (cnt > m)
        {
            left = mid + 1;
        }
        else
        {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans;
    return 0;
}