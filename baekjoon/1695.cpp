#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[5001][5001];

int main()
{
    int n;
    int str1[5001], str2[5001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str1[i];
    copy(str1, str1 + n, str2);
    reverse(str2, str2 + n);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (str1[i] == str2[j])
            {
                arr[i + 1][j + 1] = arr[i][j] + 1;
                if (result < arr[i][j] + 1)
                    result = arr[i][j] + 1;
            }
            else
            {
                arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
            }
        }
    }
    cout << n - result;
    return 0;
}