#include <iostream>
#include <vector>
using namespace std;

#define ll long long

long long seg[400005];
long long arr[100001];
vector<ll> ans;
int N, M;

ll initSeg(int node, int start, int end)
{
    if (start == end)
        return seg[node] = arr[start];
    int mid = (start + end) / 2;
    return seg[node] = min(initSeg(node * 2, start, mid), initSeg(node * 2 + 1, mid + 1, end));
}

ll query(int node, int start, int end, int left, int right)
{
    if (end < left || right < start)
        return 1e9;
    if (left <= start && end <= right)
        return seg[node];
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    initSeg(1, 0, N - 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ans.push_back(query(1, 0, N - 1, a - 1, b - 1));
    }
    for (ll answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}