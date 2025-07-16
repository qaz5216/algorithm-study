#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int record[100001];
int arr[101];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    fill(record + 1, record + 100001, 100001);
    for (int i = 1; i <= n; i++)
    {
        for (int j = arr[i]; j <= k; j++)
        {
            record[j] = min(record[j], record[j - arr[i]] + 1);
        }
    }
    if (record[k] == 100001)
        cout << -1;
    else
        cout << record[k];
    return 0;
}