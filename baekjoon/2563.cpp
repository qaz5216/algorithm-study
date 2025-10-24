#include <iostream>

using namespace std;

int n;

bool map[101][101];

int main()
{
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int x = a; x < a + 10; x++)
        {
            for (int y = b; y < b + 10; y++)
            {
                ans += !map[x][y];
                map[x][y] = true;
            }
        }
    }
    cout << ans;
    return 0;
}
