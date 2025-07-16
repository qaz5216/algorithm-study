#include <iostream>

using namespace std;
int a, b;
int f[41];

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        a++;
        return 1;
    }
    else
        return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        b++;
    }
    return f[n];
}

int main()
{
    int n;
    cin >> n;
    a = 0;
    b = 0;
    f[1] = f[2] = 1;
    fib(n);
    fibonacci(n);
    cout << a << " " << b;
    return 0;
}