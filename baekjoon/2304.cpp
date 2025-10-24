#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    int sum = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, vec[i].second);
    }
    int tmp = 0;
    int midx = 0;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (tmp <= vec[i].second)
        {
            sum += (tmp * (vec[i].first - vec[idx].first));
            tmp = vec[i].second;
            idx = i;
        }
        if (tmp == mx)
        {
            midx = i;
            break;
        }
    }
    tmp = 0;
    idx = n - 1;
    for (int i = n - 1; i >= midx; i--)
    {
        if (tmp <= vec[i].second)
        {
            sum += (tmp * abs(vec[i].first - vec[idx].first));
            tmp = vec[i].second;
            idx = i;
        }
        if (i == midx)
        {
            break;
        }
    }
    sum += mx;
    cout << sum;
    return 0;
}