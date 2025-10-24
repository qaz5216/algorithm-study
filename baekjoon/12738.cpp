#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[1000001];
int idx[1000001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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
    cout << v.size();
    return 0;
}