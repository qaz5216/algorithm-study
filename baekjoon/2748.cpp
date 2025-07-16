#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long record[45] = {
    0,
};

long long fib(int n)
{
    if (record[n] != 0)
    {
        return record[n];
    }
    else
    {
        if (n == 0)
        {
            record[n] = 0;
            return 0;
        }
        else if (n <= 2)
        {
            record[n] = 1;
            return 1;
        }
        else
        {
            record[n] = fib(n - 2) + fib(n - 1);
            return record[n];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
}