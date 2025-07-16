#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[301] = {
    0,
};
int stair[301] = {
    0,
};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> stair[i];
    }
    record[1] = stair[1];
    if (n > 1)
        record[2] = record[1] + stair[2];
    record[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for (int i = 4; i < n + 1; i++)
    {
        record[i] = max(record[i - 3] + stair[i - 1] + stair[i], record[i - 2] + stair[i]);
    }
    cout << record[n];

    return 0;
}