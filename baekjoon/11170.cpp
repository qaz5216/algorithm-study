#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    int N, M;
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        int num = 0;
        for (int i = N; i <= M; i++)
        {
            string s = to_string(i);
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == '0')
                {
                    num++;
                }
            }
        }
        cout << num << "\n";
    }
    return 0;
}