#include <iostream>

using namespace std;

int arr[100001];
pair<int, int> seg[400004];

pair<int, int> initseg(int node, int s, int e)
{
    if (s == e)
        return seg[node] = {arr[s], s};
    int mid = (s + e) / 2;
    pair<int, int> left = initseg(node * 2, s, mid);
    pair<int, int> right = initseg(node * 2 + 1, mid + 1, e);
    pair<int, int> cur = right;
    if (left.first <= right.first)
    {
        cur = left;
    }
    return seg[node] = cur;
}

pair<int, int> update(int node, int s, int e, int pos, int val)
{
    if (pos < s || e < pos)
        return seg[node];
    if (s == e)
        return seg[node] = {val, s};
    int mid = (s + e) / 2;
    pair<int, int> left = update(node * 2, s, mid, pos, val);
    pair<int, int> right = update(node * 2 + 1, mid + 1, e, pos, val);
    pair<int, int> cur = right;
    if (left.first <= right.first)
    {
        cur = left;
    }
    return seg[node] = cur;
}

pair<int, int> query(int node, int s, int e, int l, int r)
{
    if (r < s || e < l)
        return {1e9 + 1, 100001};
    if (l <= s && e <= r)
        return seg[node];
    int mid = (s + e) / 2;
    pair<int, int> left = query(node * 2, s, mid, l, r);
    pair<int, int> right = query(node * 2 + 1, mid + 1, e, l, r);
    pair<int, int> cur = right;
    if (left.first <= right.first)
    {
        cur = left;
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    initseg(1, 1, n);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, 1, n, b, c);
        }
        else
        {
            if (b > c)
                swap(b, c);
            cout << query(1, 1, n, b, c).second << "\n";
        }
    }
    return 0;
}