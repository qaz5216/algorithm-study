#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int p[1001];

struct edge
{
    int cost;
    int start;
    int dest;
    edge(int x, int a, int b)
    {
        cost = x;
        start = a;
        dest = b;
    }
};
struct cmp
{
    bool operator()(edge a, edge b)
    {
        return a.cost > b.cost;
    }
};
int find(int x)
{
    if (x == p[x])
        return x;
    return p[x] = find(p[x]);
}

bool isUnion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    return false;
}

void myunion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a > b)
        swap(a, b);
    p[b] = a;
}

int n, m, k;
priority_queue<edge, vector<edge>, cmp> q;
vector<edge> v;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(edge(i, a, b));
    }
    bool flag = false;
    while (k--)
    {
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        if (flag)
        {
            cout << 0 << " ";
            continue;
        }
        int score = 0;
        vector<edge> tmpv;
        priority_queue<edge, vector<edge>, cmp> tmpq;
        // vector꺼내서 q 삽입
        while (!q.empty())
        { // q초기화
            q.pop();
        }
        for (edge e : v)
        {
            q.push(e);
        }
        // mst 만들기
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }
        while (!q.empty())
        {
            edge cur = q.top();
            q.pop();
            if (isUnion(cur.start, cur.dest))
            {
                tmpv.push_back(cur); // 나머지는 vector에 보관
            }
            else
            {
                myunion(cur.start, cur.dest);
                score += cur.cost;
                tmpq.push(cur);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (find(i) != 1)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << 0 << " ";
            continue;
        }
        else
        {
            cout << score << " ";
            // 제일작은간선 제거
            if (!tmpq.empty())
                tmpq.pop();
        }
        v = tmpv; // 벡터에 보관
        while (!tmpq.empty())
        {
            v.push_back(tmpq.top());
            tmpq.pop();
        }
    }
    return 0;
}