#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
int myarr[1000001];
unordered_map<int, bool> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int len = 0;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr[i] = x;
        if (m[x])
            continue;
        m[x] = true;
        myarr[len] = x;
        len++;
    }
    sort(myarr, myarr + len);
    int l = 0;
    int r = len - 1;
    int mid;
    for (int i = 0; i < n; i++)
    {
        x = arr[i];
        l = 0;
        r = len - 1;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (x <= myarr[mid])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        cout << l << ' ';
    }

    return 0;
}