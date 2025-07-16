#include <iostream>

using namespace std;
int n, m;
int arr[100003];
int seg[400001];

int initseg(int node, int s, int e)
{
    if (s == e)
        return seg[node] = e;
    int mid = (s + e) / 2;
    int left = initseg(node * 2, s, mid);
    int right = initseg(node * 2 + 1, mid + 1, e);
    return arr[left] <= arr[right] ? seg[node] = left : seg[node] = right;
}

void printseg(int node, int s, int e)
{
    cout << "s=" << s << "e=" << e << " seg=" << seg[node];
    if (s == e)
        cout << " arr=" << arr[e];
    cout << "\n";
    if (s == e)
        return;
    int mid = (s + e) / 2;
    printseg(node * 2, s, mid);
    printseg(node * 2 + 1, mid + 1, e);
    return;
}

int updateseg(int node, int s, int e, int idx)
{
    if (idx < s || e < idx)
        return seg[node];
    if (s == e)
        return seg[node] = e;
    int mid = (s + e) / 2;
    int left = updateseg(node * 2, s, mid, idx);
    int right = updateseg(node * 2 + 1, mid + 1, e, idx);
    return arr[left] <= arr[right] ? seg[node] = left : seg[node] = right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    arr[n] = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    initseg(1, 0, n - 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int idx, val;
            cin >> idx >> val;
            arr[idx - 1] = val;
            updateseg(1, 0, n - 1, idx - 1);
            // printseg(1,0,n-1);
        }
        else
        {
            cout << seg[1] + 1 << '\n';
        }
    }
    return 0;
}

/*
5 4 3 2 5

*/