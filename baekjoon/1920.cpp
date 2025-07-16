#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> arr2;

int main()
{
    int N;
    cin >> N;
    int T;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        arr.push_back(T);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> T;
        arr2.push_back(T);
    }
    sort(arr.begin(), arr.end());
    int C;
    int mid, start, end;
    for (int i = 0; i < M; i++)
    {
        start = 0, end = N;
        C = 0;
        while (end - start >= 0)
        {
            mid = (start + end) / 2;
            if (arr[mid] == arr2[i])
            {
                C = 1;
                break;
            }
            else if (arr[mid] > arr2[i])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << C << "\n";
    }
    return 0;
}