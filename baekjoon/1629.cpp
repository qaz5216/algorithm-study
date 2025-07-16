#include <iostream>

using namespace std;

#define ll long long

ll A, B, C;

ll namage(ll x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return A % C;
    ll k = namage(x / 2) % C;
    if (x % 2 == 0)
        return k * k % C;
    else
        return (k * k % C) * (A % C);
}

int main()
{
    cin >> A >> B >> C;
    cout << namage(B) % C;
    return 0;
}