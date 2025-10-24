#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int student[4][1001]; // 반,학생

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> sum;
    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        int ans = 1e9;
        sum.resize(0);
        cin >> k >> n;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> student[i][j];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum.push_back(student[0][i] + student[1][j]);
            }
        }
        sort(sum.begin(), sum.end());
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = student[2][i] + student[3][j];
                int l = 0;
                int r = sum.size();
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (sum[mid] < k - tmp)
                    {
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid;
                    }
                }
                if (r == 0)
                {
                    tmp += sum[r];
                }
                else
                {
                    if (abs(k - (tmp + sum[r - 1])) <= abs(k - (tmp + sum[r])))
                    {
                        tmp += sum[r - 1];
                    }
                    else
                    {
                        tmp += sum[r];
                    }
                }
                if (abs(k - tmp) == abs(k - ans))
                {
                    ans = min(tmp, ans);
                }
                else if (abs(k - tmp) < abs(k - ans))
                {
                    ans = tmp;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
