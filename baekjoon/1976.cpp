#include <iostream>
#include <vector>

using namespace std;

int N, M;
int p[201];

int find(int x)
{
    if (x == p[x])
        return x;
    else
        return find(p[x]);
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return;
    }
    else
    {
        if (a > b)
            p[a] = b;
        else
            p[b] = a;
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        p[i] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
                myunion(i, j);
        }
    }
    int parent;
    cin >> parent;
    parent = find(parent);
    bool can = true;
    for (int i = 1; i < M; i++)
    {
        int a;
        cin >> a;
        if (i == 0)
            parent = p[a];
        else
        {
            if (parent != find(a))
            {
                can = false;
            }
        }
    }
    if (can)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}