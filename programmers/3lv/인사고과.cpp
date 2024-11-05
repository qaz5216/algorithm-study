#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
근무태도 높은순서대로 정렬
그중 y가 가장높은것을 컷으로 결정
*/

bool comp(vector<int> a,vector<int> b)
{
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]>b[0];
}

int solution(vector<vector<int>> scores) {
    int ansx=scores[0][0];
    int ansy=scores[0][1]; 
    int anssum=ansx+ansy; // 완호의 점수
    int answer = 0;
    priority_queue<int> pq;
    sort(scores.begin(),scores.end(),comp);
    int minx=100001;
    int cut=-1;
    int ncut=-1;//다음으로 작은x에서 쓸 cut
    bool flag=true; // 완호 제외검사
    for(vector<int> v : scores)
    {
        if(minx>v[0]) {
            minx=v[0];
            if(ncut>cut) cut=ncut;
            if(v[1]>ncut) ncut=v[1];
        }
        if(cut<=v[1])//컷안에 들어간다면
        {
            pq.push(v[0]+v[1]);
        }
        if(v[0]==ansx&&flag){ //완호가 커트에 걸리진 않는가?
            flag=false;
            if(cut>ansy) return -1;
        }
    }
    bool flag2=true;//완호찾기
    while(!pq.empty()&&flag2)
    {
        int cur=pq.top();pq.pop();
        if(cur==anssum)
        {
            flag2=false;
        }
        answer+=1;   
    }
    return answer;
}