#include <iostream>

using namespace std;

int n, k;
int arr[200001];
int record[100001];
int ans = 0;

int main()
{
    cin >> n >> k;
    int l = 0;
    for (int i = 0; i < n; i++)
    { // i=r임
        cin >> arr[i];
        if (++record[arr[i]] > k)
        {
            ans = max(ans, i - l);
            while (l < i)
            {
                record[arr[l]]--;
                l++;
                if (arr[l - 1] == arr[i])
                    break;
            }
        }
    }
    ans = max(ans, n - l); // 마지막 검사
    cout << ans;
    return 0;
}
/*

*/