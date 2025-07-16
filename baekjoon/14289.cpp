#include <iostream>
#include <vector>

using namespace std;
#define ll long long
#define mat vector<vector<ll>>

const ll mod = 1e9 + 7;

mat mul(mat a, mat b)
{
    mat c(a.size(), vector<ll>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b[0].size(); j++)
            for (int k = 0; k < b.size(); k++)
            {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
    return c;
}

mat pow(mat a, ll n)
{
    if (n == 1)
        return a;
    if (n % 2 == 1)
        return mul(pow(a, n - 1), a);
    mat tmp = pow(a, n / 2);
    return mul(tmp, tmp);
}

int main()
{
    int n, m;
    ll d;
    cin >> n >> m;
    int a, b;
    mat arr(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        arr[a - 1][b - 1] = 1;
        arr[b - 1][a - 1] = 1;
    }
    cin >> d;
    arr = pow(arr, d);
    cout << arr[0][0];
    return 0;
}