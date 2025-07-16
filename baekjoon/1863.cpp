#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
int arr[50001];
stack<int> s;
int ans = 0;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (y != 0)
        { // 0이 아니면
            if (s.empty())
            { // 비어있으면 넣어
                s.push(y);
                ans++;
            }
            else
            {
                int t = s.top();
                if (t < y)
                { // 스택위보다 크냐?
                    s.push(y);
                    ans++;
                }
                else
                {
                    while (!s.empty() && s.top() > y)
                    { // 나보다 큰거 다빼기
                        s.pop();
                    }
                    if (!s.empty())
                        if (s.top() == y)
                            continue; // top이 지금과 같으면 그냥 넘어가기
                    s.push(y);        // top이 y보다 작으면
                    ans++;            // 넣어
                }
            }
        }
        else
        { // 0 이면 다빼
            while (!s.empty())
            {
                s.pop();
            }
        }
    }
    cout << ans;
    return 0;
}
/*


*/