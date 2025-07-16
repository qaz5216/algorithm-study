#include <iostream>
#include <algorithm>
using namespace std;

int arr[2001];

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
        int l = 0;
        int r = n - 1;
        bool flag = false;
        while (l < r)
        {
            int sum = arr[l] + arr[r];
            if (sum > arr[i])
            {
                r--;
            }
            else if (sum < arr[i])
            {
                l++;
            }
            else
            {
                if (r != i && l != i)
                {
                    flag = true;
                    break;
                }
                else if (l == i)
                    l++;
                else if (r == i)
                    r--;
            }
        }
        if (flag)
        {
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}