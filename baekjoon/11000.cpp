#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
pair<int, int> arr[200001];
priority_queue<int,
               vector<int>,
               greater<int>>
    pq;
int mx;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    mx = 0;
    for (int i = 0; i < n; i++)
    {
        while (!pq.empty())
        {
            int t = pq.top();
            if (t <= arr[i].first) // 끝나는시간이 지금강의시작시간보다 작으면
                pq.pop();
            else
            {
                break;
            }
        }
        pq.push(arr[i].second);       // 큐에 끝나는시간 넣기
        mx = max(mx, (int)pq.size()); // pq.size()=강의실 개수
    }
    cout << mx;
    return 0;
}