#include <iostream>

using namespace std;

#define ll long long
ll INF = 1e6;

int fisano_period(int m)
{
    int count = 0, ex = 0, now = 1;
    do
    {
        int tmp = now + ex;
        ex = now;
        now = tmp % m;
        count++;
    } while (ex != 0 || now != 1);
    return count;
}

int main()
{
    ll t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << n << " " << fisano_period(m) << "\n";
    }
    return 0;
}