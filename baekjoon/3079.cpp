#include <bits/stdc++.h>

using namespace std;
int N, M;
long long sim[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    long long mnum = 1e9;
    for (int i = 0; i < N; i++)
    {
        cin >> sim[i];
        mnum = min(mnum, sim[i]);
    }
    long long high = mnum * M;
    long long low = 0;
    while (high > low + 1)
    {
        long long mid = (high + low) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += mid / sim[i];
        }
        if (sum >= M)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    cout << high;
    return 0;
}