#include <iostream>

using namespace std;

#define ll long long

int N;
ll arr[100001];

ll cal(int start, int end)
{
    if (start == end)
        return arr[start] * arr[start];
    int l, r, mid;
    mid = (start + end) / 2;
    l = mid;
    r = mid + 1;
    ll result = max(cal(start, l), cal(r, end));
    ll h = min(arr[l], arr[r]);
    ll sum = arr[l] + arr[r];
    result = max(result, sum * h);
    while (start < l || r < end)
    {
        if (start == l)
        {
            h = min(h, arr[++r]);
            sum += arr[r];
        }
        else if (end == r)
        {
            h = min(h, arr[--l]);
            sum += arr[l];
        }
        else if (arr[l - 1] > arr[r + 1])
        {
            h = min(h, arr[--l]);
            sum += arr[l];
        }
        else
        {
            h = min(h, arr[++r]);
            sum += arr[r];
        }
        result = max(result, sum * h);
    }
    return result;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << cal(0, N - 1);
    return 0;
}