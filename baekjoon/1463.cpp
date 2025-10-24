#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int record[1000001] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    record[1] = 1;
    record[2] = 2;
    record[3] = 3;
    if (n >= 4)
        for (int i = 4; i < n + 1; i++)
        {
            record[i] = record[i - 1] + 1;
            if (i % 3 == 0)
                if (record[i] > record[i / 3] + 1)
                    record[i] = record[i / 3] + 1;
            if (i % 2 == 0)
                if (record[i] > record[i / 2] + 1)
                    record[i] = record[i / 2] + 1;
        }
    cout << record[n];
    return 0;
}