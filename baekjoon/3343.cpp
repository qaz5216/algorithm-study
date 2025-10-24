#include <iostream>
#include <cmath>
using namespace std;

#define ll long long

ll N;
ll A, B, C, D;
pair<ll, ll> expen;
pair<ll, ll> cheap;
ll ans = (ll)10e18;

int main()
{
    cin >> N >> A >> B >> C >> D;
    expen = {A, B};
    cheap = {C, D};
    if ((double)B / (double)A < (double)D / (double)C)
    {
        swap(expen, cheap);
    }
    else if ((double)B / (double)A == (double)D / (double)C)
    {
        if (A > C)
            swap(expen, cheap);
    }
    for (ll b = 0; b < cheap.first; b++)
    {
        ll a = ceil((double)(N - (b * expen.first)) / (double)cheap.first);
        if (a < 0)
        {
            a = 0;
            ans = min(ans, expen.second * b);
            break;
        }
        ans = min(ans, cheap.second * a + expen.second * b);
    }
    cout << ans;
    return 0;
}

/*

*/