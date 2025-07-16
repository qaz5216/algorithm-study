#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    vector<int> homes;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        homes.push_back(tmp);
    }
    sort(homes.begin(), homes.end());
    if (homes.size() % 2 == 0)
    {
        cout << homes[homes.size() / 2 - 1];
    }
    else
    {
        cout << homes[homes.size() / 2];
    }

    return 0;
}