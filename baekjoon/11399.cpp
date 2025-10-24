#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int ans;
vector<int> arr;
vector<int> time;

void solve()
{
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        ans += sum;
    }
    return;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    ans = 0;
    solve();
    cout << ans;
}