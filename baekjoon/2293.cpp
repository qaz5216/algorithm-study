#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int record[10000];
int coin[100];
int main()
{
    int n, k, result, tmp;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
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
    cout << record[k];
    return 0;
}