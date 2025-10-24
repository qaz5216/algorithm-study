#include <iostream>
#include <vector>
using namespace std;

#define ll long long

const ll Mx = 1e9 + 7;
int N, M, K;
ll arr[1000001];
ll seg[4000005];
vector<ll> ans;

ll init(int node, int start, int end)
{
    if (start == end)
        return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end) % Mx;
}

ll update(int node, int start, int end, int pos, int val)
{
    if (pos < start || end < pos)
        return seg[node];
    if (start == end)
        return seg[node] = val;
    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, pos, val) * update(node * 2 + 1, mid + 1, end, pos, val) % Mx;
}

ll query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return 1;
    if (left <= start && end <= right)
        return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right) % Mx;
}

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    for (int i = 0; i < M + K; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            update(1, 0, N - 1, b - 1, c);
        }
        else
        {
            if (b > c)
                swap(b, c);
            ans.push_back(query(1, 0, N - 1, b - 1, c - 1));
        }
    }
    for (ll answer : ans)
    {
        cout << answer << "\n";
    }
}