#include <iostream>
#include <queue>
using namespace std;

int n, k, cnt;
int arr[1000001];
int ans = 0;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cnt = 0;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            cnt++;
            if (k == 0) // q.pop안되니까 따로처리
            {
                ans = max(ans, i - left);
                left = i + 1;
            }
            else
            {
                if (cnt > k)
                {
                    // ans갱신 i-l-(cnt-1)?
                    ans = max(ans, i - left - cnt + 1);
                    // left 갱신 l=q.front()+1?
                    left = q.front() + 1;
                    q.pop();
                    cnt--;
                }
                q.push(i);
            }
        }
    }
    ans = max(ans, n - left - cnt);
    cout << ans;
    return 0;
}