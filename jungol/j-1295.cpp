#include <iostream>

using namespace std;
int n, t;
int arr[50001];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> t;
    while (t--)
    {
        int target;
        cin >> target;
        int left = 0;
        int right = n;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (target <= arr[mid])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left == n)
            cout << "0\n";
        else
        {
            if (arr[left] != target)
            {
                cout << "0\n";
            }
            else
            {
                cout << left + 1 << '\n';
            }
        }
    }
    return 0;
}