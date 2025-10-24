#include <iostream>

using namespace std;

int T;
int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        if (N == M)
        {
            cout << 1 << "\n";
            continue;
        }
        int ans = 1;
        for (int i = M; i > M - N; i--)
        {
            ans *= i;
            ans = ans / (M - i + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}

/*
nCm=n

*/