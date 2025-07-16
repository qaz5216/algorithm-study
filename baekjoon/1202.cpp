#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> arr[300001];
bool check[300001];
int bag[300001];

priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bag[i];
    }
    sort(arr, arr + n);
    sort(bag, bag + k);
    long long sum = 0;
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && bag[i] >= arr[idx].first)
        {
            pq.push(arr[idx].second);
            idx++;
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}

/*

1 150
2 100

작은가방부터 비싼거대로 넣기
*/