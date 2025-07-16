#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[10001] = {
    0,
};
int arr[10001] = {
    0,
};
int main()
{
    int n, result;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    record[1] = arr[1];
    record[2] = arr[1] + arr[2];
    record[3] = max(arr[1], arr[2]) + arr[3];
    for (int i = 3; i < n + 1; i++)
    {
        record[i] = max(max(record[i - 3] + arr[i - 1], record[i - 2]) + arr[i], record[i - 1]);
    }
    cout << record[n];
    return 0;
}
