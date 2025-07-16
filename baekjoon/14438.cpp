#include <iostream>
#include <vector>
using namespace std;

int N, M;
int Minseg[400005];
int arr[100001];
vector<int> ans;

int initSeg(int node, int start, int end)
{
    if (start == end)
        return Minseg[node] = arr[start];
    int mid = (start + end) / 2;
    return Minseg[node] = min(initSeg(node * 2, start, mid), initSeg(node * 2 + 1, mid + 1, end));
}

int Update(int node, int start, int end, int pos, int val)
{
    if (pos < start || end < pos)
        return Minseg[node];
    if (start == end)
        return Minseg[node] = val;
    int mid = (start + end) / 2;
    return Minseg[node] = min(Update(node * 2, start, mid, pos, val), Update(node * 2 + 1, mid + 1, end, pos, val));
}

int query(int node, int start, int end, int left, int right)
{
    if (right < start || end < left)
        return 1e9;
    if (left <= start && end <= right)
        return Minseg[node];
    int mid = (start + end) / 2;
    return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    initSeg(1, 0, N - 1);
    cin >> M;

    while (M--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            Update(1, 0, N - 1, b - 1, c);
            arr[b] = c;
        }
        else
        {
            if (b > c)
                swap(b, c);
            ans.push_back(query(1, 0, N - 1, b - 1, c - 1));
        }
    }
    for (int answer : ans)
    {
        cout << answer << "\n";
    }
    return 0;
}