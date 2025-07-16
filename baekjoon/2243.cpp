#include <iostream>

using namespace std;

#define ll long long

ll seg[4000001];

int n;

ll query(int node, int s, int e, int cnt)
{
    if (s == e)
        return s;
    int mid = (s + e) / 2;
    if (seg[node * 2] >= cnt)
        return query(node * 2, s, mid, cnt);
    return query(node * 2 + 1, mid + 1, e, cnt - seg[node * 2]);
}

ll update(int node, int s, int e, int pos, int val)
{
    if (pos < s || e < pos)
        return seg[node];
    if (s == e)
        return seg[node] += val;
    int mid = (s + e) / 2;
    return seg[node] = update(node * 2, s, mid, pos, val) + update(node * 2 + 1, mid + 1, e, pos, val);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            ll b;
            cin >> b;
            int k = query(1, 1, 1000001, b);
            cout << k << "\n";
            update(1, 1, 1000001, k, -1);
        }
        else
        {
            ll b, c;
            cin >> b >> c;
            update(1, 1, 1000001, b, c);
        }
    }
    return 0;
}
