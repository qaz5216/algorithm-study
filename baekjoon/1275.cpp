#include <iostream>

using namespace std;

#define ll long long

ll arr[100001];
ll seg[400004];

int n, q;

ll initseg(int node, int s, int e)
{
    if (s == e)
        return seg[node] = arr[s];
    int mid = (s + e) / 2;
    return seg[node] = initseg(node * 2, s, mid) + initseg(node * 2 + 1, mid + 1, e);
}

ll update(int node, int s, int e, int pos, ll val)
{
    if (pos < s || e < pos)
        return seg[node];
    if (s == e)
        return seg[node] = val;
    int mid = (s + e) / 2;
    return seg[node] = update(node * 2, s, mid, pos, val) + update(node * 2 + 1, mid + 1, e, pos, val);
}

ll query(int node, int s, int e, int l, int r)
{
    if (e < l || r < s)
        return 0;
    if (l <= s && e <= r)
        return seg[node];
    int mid = (s + e) / 2;
    return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    initseg(1, 0, n - 1);
    while (q--)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);
        cout << query(1, 0, n - 1, x - 1, y - 1) << "\n";
        update(1, 0, n - 1, a - 1, b);
    }
    return 0;
}