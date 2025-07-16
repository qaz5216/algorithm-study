#include <iostream>

using namespace std;

int n, q, m, l, r, x;
int arr[100001];
int seg[400001];
int lazy[400001];

int initseg(int node, int left, int right)
{
    if (left == right)
    {
        return seg[node] = arr[left];
    }
    int mid = (left + right) / 2;
    return seg[node] = initseg(node * 2, left, mid) + initseg(node * 2 + 1, mid + 1, right);
}

void propagation(int node, int left, int right)
{
    if (lazy[node] == 0)
    {
        return;
    }
    seg[node] += lazy[node] * (right - left + 1);
    if (left != right)
    {
        int mid = (left + right) / 2;
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        lazy[node] = 0;
    }
}
/*
0 4


*/
int query(int node, int left, int right, int target)
{
    if (target < left || right < target)
    {
        return 0;
    }
    propagation(node, left, right);
    if (left == right)
    {
        return seg[node];
    }
    else
    {
        int mid = (left + right) / 2;
        return query(node * 2, left, mid, target) + query(node * 2 + 1, mid + 1, right, target);
    }
}

void update(int node, int left, int right, int start, int end)
{
    propagation(node, left, right);
    if (start <= left || right <= end)
    {
        lazy[node] += 1;
        return;
    }
    else
    {
        int mid = (left + right) / 2;
        update(node * 2, left, mid, start, end);
        update(node * 2 + 1, mid + 1, right, start, end);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    initseg(1, 0, n - 1);
    cin >> q;
    while (q--)
    {
        cin >> m;
        if (m == 1)
        {
            cin >> l >> r;
            update(1, 0, n - 1, l - 1, r - 1);
        }
        else
        {
            cin >> x;
            cout << query(1, 0, n - 1, x - 1) << '\n';
        }
    }
    return 0;
}
/*
한번 쭉입력받고
record[]배열 작성

그다음 쿼리를 한번더 실행하면서
record[]와의 차이를 통해 계산?
ㄴㄴ
쿼리마다 딱딱나와야댐..

??
log n*q
레이지세그;;;


1 2 1 2 1

1 1 1 1 1

1 2 3 4 5
  1 1 1 1
1 2 2 2 2
1 3 5 7 9
1 1 1 1
2 5 8 11 9


*/