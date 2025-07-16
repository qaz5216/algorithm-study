#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1001];
int idx;
int main()
{
    cin >> n;
    idx = 0;
    int x;
    cin >> x;
    arr[idx] = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x < arr[idx])
        {
            arr[++idx] = x;
        }
        else
        {
            int l = 0;
            int r = idx + 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (arr[mid] > x)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            if (l <= idx)
            {
                arr[l] = x;
            }
            // 들어갈 자리찾기 이분탐색으로
        }
    }

    cout << idx + 1;

    return 0;
}
// l=0 r=4;
/*
mid=2
arr[2]=3
l=0 r=2;
mid=1
arr[1]=5
l=1;
l=1 r=2;
mid=1
l=2 r=2;
*/