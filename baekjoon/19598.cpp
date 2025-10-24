#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int s, e;
        cin >> s >> e;
        vec.push_back({s, e});
    }
    sort(vec.begin(), vec.end());
    int ans = 1;
    int idx = 0;
    pq.push(vec[0].second);
    for (int i = 1; i < vec.size(); i++)
    {
        if (pq.top() <= vec[i].first)
        {
            pq.push(vec[i].second);
            pq.pop();
        }
        else
        {
            pq.push(vec[i].second);
        }
    }
    cout << pq.size();
    return 0;
}