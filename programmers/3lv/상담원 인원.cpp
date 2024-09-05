#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int num;
int mk;

vector<vector<int>> arr;

void dfs(int k,int x,vector<int> v)//남은 인원수
{
    if(k>mk)
    {
        if(x==0)
        {
            arr.push_back(v);
        }
        return;
    }
    for(int i=0;i<=x;i++)
    {
        v.push_back(i);
        dfs(k+1,x-i,v);
        v.pop_back();
    }
}
int solution(int k, int n, vector<vector<int>> reqs) {
    int answer = 1e9;
    num=n;
    mk=k;
    dfs(1,n-k,vector<int>());
    for(vector<int> v:arr)
    {   //한경우씩 계산하기
        for(int i=0;i<v.size();i++)
        {
            v[i]+=1; //상담원수
        }
        int sum=0;
        priority_queue<int,vector<int>,greater<int>> pq[v.size()];
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i];j++)
            {
                pq[i].push(0);
            }
        }
        for (vector<int> req : reqs)
        {
            int s=req[0];
            int t=req[1];
            int type=req[2]-1;
            int time=pq[type].top();
            pq[type].pop();
            if(time>s)
            {
                sum+=time-s;
                pq[type].push(time+t);
            }
            else
            {
                pq[type].push(s+t);
            }
        }
        answer=min(answer,sum);
    }
    return answer;
}