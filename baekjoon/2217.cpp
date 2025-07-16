#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, arr[i] * (n - i));
    }
    cout << ans;
    return 0;
}