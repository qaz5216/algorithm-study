#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[5001][5001];

int main()
{
    int n;
    string str1, str2;
    cin >> n >> str1;
    str2 = str1;
    reverse(str2.begin(), str2.end());
    int result = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        for (int j = 0; j < str2.length(); j++)
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