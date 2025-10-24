#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
priority_queue<
    int,
    vector<int>,
    greater<int>>
    greatpq;                // 중간값보다 큰애들
priority_queue<int> lesspq; // 중간값보다 작은애들

void push(int x, bool hol)
{ // 홀수일땐 great에 짝수일땐 less에
    int mid;
    if (hol)
    { // great에넣기
        mid = greatpq.top();
        if (x >= mid)
        { // x가 mid보다크면
            greatpq.push(x);
        }
        else
        { // X가 mid보다 작으면
            if (lesspq.top() > x)
            { // lesstop이 x보다크면
                greatpq.push(lesspq.top());
                lesspq.pop();
                lesspq.push(x);
            }
            else
            {
                greatpq.push(x);
            }
        }
        cout << greatpq.top() << '\n';
    }
    else
    { // less에 넣기
        mid = lesspq.top();
        if (x <= mid)
        {
            lesspq.push(x);
        }
        else
        {
            if (greatpq.top() < x)
            {
                lesspq.push(greatpq.top());
                greatpq.pop();
                greatpq.push(x);
            }
            else
            {
                lesspq.push(x);
            }
        }
        cout << lesspq.top() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int x;
    cin >> x;
    greatpq.push(x);
    cout << x << '\n';
    if (n >= 2)
    {
        cin >> x;
        if (greatpq.top() < x)
        {
            cout << greatpq.top() << '\n';
            lesspq.push(greatpq.top());
            greatpq.pop();
            greatpq.push(x);
        }
        else
        {
            cout << x << '\n';
            lesspq.push(x);
        }
        for (int i = 3; i <= n; i++)
        {
            cin >> x;
            push(x, i % 2);
        }
    }
    return 0;
}
/*
100000만
10만*10만/2
50 0000 0000
시간줄여..
pq index로 접근되냐..?

일단 다받자
10만*(인덱스접근)
인덱스접근 O(n)이하로 해야댐;

중간값 계속 들고있자
들어오는게 더 작은가?
더큰가? 비교해서
더작으면 앞에 넣고
더크면 뒤에 넣고
트리구조로 짜야될거같음
이진트리
좌우 균형 맞추는 트리
왼쪽pq 하나 오른쪽 pq 하나
중간값보다 작으면
왼쪽pq에서 제일큰값
중간값보다 크면
오른쪽pq에서 제일 작은값

2개까지는 그냥넣자..
*/