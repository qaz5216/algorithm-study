#include <iostream>

using namespace std;

int n, m;
int arr[100001];
int record[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int a, b, k;
    while (m--)
    {
        cin >> a >> b >> k;
        record[a] += k;
        record[b + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        record[i] += record[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] + record[i] << ' ';
    }

    return 0;
}