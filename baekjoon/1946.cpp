#include <iostream>
#include <algorithm>
using namespace std;
int t, n;
pair<int, int> arr[100001];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) // 서류등수가 같으면
    {
        return a.second < b.second; // 면접등수순으로
    }
    return a.first < b.first;
}
/*
nlogn
longist increase? x
점수x 등수임
*/
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr, arr + n, cmp);
        int cnt = 1;             // 제일 등수높은사람
        int tmp = arr[0].second; // 면접등수
        for (int i = 1; i < n; i++)
        {
            if (arr[i].second < tmp)
            { // tmp=그전인덱스 면접등수
                cnt++;
                tmp = arr[i].second; // tmp에 갱신
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}