#include <iostream>

using namespace std;

int n, m;
int arr[1000001];
long long ans = 1000000000000;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long l = 0;
    long long r = ans;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += mid / arr[i];
        }
        if (cnt >= m)
        {
            ans = min(mid, ans);
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