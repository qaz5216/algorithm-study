#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[1001];
int idx[1001];
int n;
vector<int> v;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (v.size() == 0 || v[v.size() - 1] < arr[i])
        {
            v.push_back(arr[i]);
            idx[i] = v.size() - 1;
        }
        else
        {
            int l = 0;
            int r = v.size() - 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (v[mid] >= arr[i])
                    r = mid;
                else
                    l = mid + 1;
            }
            v[l] = arr[i];
            idx[i] = l;
        }
    }
    cout << v.size() << "\n";
    vector<int> ans;
    int cnt = v.size() - 1;
    for (int i = n; i > 0; i--)
    {
        if (idx[i] == cnt)
        {
            cnt--;
            ans.push_back(arr[i]);
        }
    }
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    return 0;
}