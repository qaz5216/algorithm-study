#include <iostream>
#include <vector>
using namespace std;

#define ll long long

int N, M, K;
ll arr[1000005];
ll tree[1000005];
vector<ll> ans;

void femod(int idx, ll diff)
{
    while (idx <= N)
    {
        tree[idx] += diff;
        idx += idx & -idx;
    }
    return;
}

ll mypresum(int idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

ll query(int s, int e)
{
    return mypresum(e) - mypresum(s);
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> arr[i];
        femod(i, arr[i]);
    }
    for (int i = 0; i < M + K; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            femod(b, c - arr[b]);
            arr[b] = c;
        }
        else
        {
            if (b > c)
                swap(b, c);
            ans.push_back(query(b - 1, c));
        }
    }
    for (ll answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}