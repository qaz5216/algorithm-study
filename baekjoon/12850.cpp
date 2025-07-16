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
    else
    {
        mat res = pow(a, n / 2);
        return mul(res, res);
    }
}

int main()
{
    ll d;
    cin >> d;
    mat A(8, vector<ll>(8, 0));
    A[0][1] = A[0][3] = 1;
    A[1][0] = A[1][2] = A[1][3] = 1;
    A[2][1] = A[2][3] = A[2][4] = A[2][5] = 1;
    A[3][0] = A[3][1] = A[3][2] = A[3][5] = 1;
    A[4][2] = A[4][5] = A[4][6] = 1;
    A[5][2] = A[5][3] = A[5][4] = A[5][7] = 1;
    A[6][4] = A[6][7] = 1;
    A[7][5] = A[7][6] = 1;
    A = pow(A, d);
    cout << A[0][0];
    return 0;
}