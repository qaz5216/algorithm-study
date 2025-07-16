#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1000001];

int main()
{
    int t, n[10], tmp;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        tmp = 0;
        while (n[i] >= 1)
        {
            if (n[i] % 2 == 1)
            {
                cout << tmp << " ";
            }
            tmp++;
            n[i] = n[i] / 2;
        }
        cout << "\n";
    }
    return 0;
}