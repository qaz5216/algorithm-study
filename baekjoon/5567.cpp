#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<pair<int, int>> arr;
int invite[501];

int main()
{
    cin >> n;
    cin >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    invite[1] = 1;
    for (pair<int, int> e : arr)
    {
        if (e.first == 1)
        {
            if (invite[e.second] == 0)
            {
                invite[e.second] = 1;
                cnt++;
            }
            for (pair<int, int> e2 : arr)
            {
                if (e2.first == e.second)
                    if (invite[e2.second] == 0)
                    {
                        invite[e2.second] = 1;
                        cnt++;
                    }
                if (e2.second == e.second)
                    if (invite[e2.first] == 0)
                    {
                        invite[e2.first] = 1;
                        cnt++;
                    }
            }
        }
        if (e.second == 1)
        {
            if (invite[e.first] == 0)
            {
                invite[e.first] = 1;
                cnt++;
            }
            for (pair<int, int> e2 : arr)
            {
                if (e2.first == e.first)
                    if (invite[e2.second] == 0)
                    {
                        invite[e2.second] = 1;
                        cnt++;
                    }
                if (e2.second == e.first)
                    if (invite[e2.first] == 0)
                    {
                        invite[e2.first] = 1;
                        cnt++;
                    }
            }
        }
    }

    cout << cnt;
    return 0;
}