#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while (T--)
    {
        priority_queue<int> pq;
        priority_queue<
            int,
            vector<int>,
            greater<int>>
            pq2;
        unordered_map<int, int> m;
        int k, num = 0, dnum = 0;
        cin >> k;
        while (k--)
        {
            char c;
            int a;
            cin >> c;
            if (c == 'I')
            {
                cin >> a;
                pq.push(a);
                pq2.push(a);
                m[a]++;
                num++;
            }
            else
            {
                cin >> a;
                if (num - dnum == 0)
                    continue;
                dnum++;
                if (a == 1)
                {
                    while (m[pq.top()] == 0)
                    {
                        pq.pop();
                    }
                    m[pq.top()]--;
                    pq.pop();
                }
                else
                {
                    while (m[pq2.top()] == 0)
                    {
                        pq2.pop();
                    }
                    m[pq2.top()]--;
                    pq2.pop();
                }
            }
        }

        while (!pq.empty() && m[pq.top()] == 0)
        {
            pq.pop();
        }
        while (!pq.empty() && m[pq2.top()] == 0)
        {
            pq2.pop();
        }
        if (num - dnum == 0)
            cout << "EMPTY\n";
        else
            cout << pq.top() << ' ' << pq2.top() << '\n';
    }
    return 0;
}
/*
큐두개쓰고 맵으로 몇개인지 관리해서 이미 삭제한건 빼기

*/