#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
    int N, M;
    cin >> N >> M;
    int T;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        arr.push_back(T);
    }
    sort(arr.begin(), arr.end());
    int start = 0, end = arr[N - 1];
    int mid;
    long long csum;
    while (end - start >= 0)
    {
        mid = (end + start) / 2;
        csum = 0;
        for (int i = 0; i < N; i++)
        {
            if (arr[i] > mid)
                csum += arr[i] - mid;
        }
        if (csum >= M)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
    return 0;
}