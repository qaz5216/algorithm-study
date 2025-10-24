#include <iostream>

using namespace std;

int p[1000001];

int find(int a)
{
    if (a == p[a])
        return a;
    return p[a] = find(p[a]);
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a > b)
        swap(a, b);
    if (a == b)
        return;
    p[b] = a;
}

void print(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 0)
        {
            myunion(a, b);
        }
        else
        {
            print(a, b);
        }
    }
    return 0;
}