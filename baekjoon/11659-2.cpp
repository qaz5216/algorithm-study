#include <iostream>

using namespace std;

int nsum[100001];

int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> nsum[i];
        nsum[i] += nsum[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << nsum[b] - nsum[a - 1] << "\n";
    }
    return 0;
}