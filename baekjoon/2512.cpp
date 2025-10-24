#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
    int N;
    cin >> N;
    long long csum = 0;
    int T;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        csum += T;
        arr.push_back(T);
    }
    long M;
    int max;
    cin >> M;
    sort(arr.begin(), arr.end());
    if (csum <= M)
        max = arr[N - 1];
    else
    {
        int start = 0, end = arr[N - 1];
        int mid;
        while (end - start >= 0)
        {
            mid = (end + start) / 2;
            csum = 0;
            for (int i = 0; i < N; i++)
            {
                if (arr[i] >= mid)
                    csum += mid;
                else
                    csum += arr[i];
            }
            if (csum <= M)
            {
                max = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
    }
    cout << max;
    return 0;
}