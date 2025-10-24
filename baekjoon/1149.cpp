#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int record[1001][3] = {
    0,
}; //[n][1] 최솟값 [n][2]마지막선택한 색깔 0,1,2 중
int home[1001][3] = {
    0,
};
int main()
{
    int n, t, result;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> home[i][j];
        }
    }
    for (int j = 0; j < 3; j++)
    {
        record[0][j] = home[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        record[i][0] = home[i][0] + min(record[i - 1][1], record[i - 1][2]);
        record[i][1] = home[i][1] + min(record[i - 1][0], record[i - 1][2]);
        record[i][2] = home[i][2] + min(record[i - 1][0], record[i - 1][1]);
    }
    result = record[n - 1][0];
    for (int j = 1; j < 3; j++)
    {
        result = min(result, record[n - 1][j]);
    }
    cout << result;
    return 0;
}