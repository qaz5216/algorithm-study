#include <iostream>

using namespace std;

int N, M;
int arr[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
    while (M--)
    {
        int start, end, time;
        cin >> start >> end >> time;
        if (arr[start][end] <= time)
            cout << "Enjoy other party\n";
        else
            cout << "Stay here\n";
    }
    return 0;
}