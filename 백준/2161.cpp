#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> q;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        cout<<q.front()<<' ';//제일위에꺼 출력
        q.pop();//제일위에꺼 뺴기
        if(!q.empty())
        {
            q.push(q.front());//두번째꺼 마지막으로넣기
            q.pop();//빼기
        }
    }
    return 0;
}