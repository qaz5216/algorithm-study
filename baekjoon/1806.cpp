#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int n, s;
int arr[100000];
int result = 100000;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int checksum = 0;
    for (int i = 0; i < n; i++)
    {
        checksum += arr[i];
    }
    if (checksum < s)
    {
        cout << 0;
        return 0;
    }
    int l = 0, r = 0;
    int sum = arr[0];
    while (l <= r && r < n)
    {
        if (sum < s)
        {
            r++;
            sum += arr[r];
        }
        else
        {
            result = min(result, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }
    cout << result;
    return 0;
}
