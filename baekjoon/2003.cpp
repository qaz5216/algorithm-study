#include <iostream>

using namespace std;

int n, m;
int arr[10001];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    int l = 0, r = 0, sum = 0;
    while (r <= n)
    {
        if (sum >= m)
        {
            sum -= arr[l];
            l++;
        }
        else
        {
            sum += arr[r];
            r++;
        }
        if (sum == m)
            cnt++;
    }
    cout << cnt;
    return 0;
}