#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int record[10000];
int main()
{
    int t, n, k, result[20], tmp;
    int coin[20];
    cin >> t;
    tmp = t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < 20; i++)
        {
            coin[i] = 0;
        }
        for (int i = 0; i < 10000; i++)
        {
            record[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        cin >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = coin[i]; j <= k; j++)
            {
                if (j == coin[i])
                    record[j]++;
                else
                    record[j] += record[j - coin[i]];
            }
        }
        result[t] = record[k];
    }
    for (int i = tmp - 1; i >= 0; i--)
    {
        cout << result[i] << "\n";
    }
    return 0;
}