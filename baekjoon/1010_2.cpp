#include <iostream>

using namespace std;

int main()
{
    int T;
    int N, M;
    cin >> T;
    while (T--)
    {
        long long ans = 1;
        cin >> N >> M;
        // cout<<mCn
        for (int i = 1; i <= N; i++)
        {
            ans *= M;
            M--;
            ans /= i;
        }
        cout << ans << "\n";
    }
    return 0;
}