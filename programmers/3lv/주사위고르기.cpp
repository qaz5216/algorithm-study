#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> arr;
vector<int> ans;
int n;
vector<int> a;
vector<int> b;
vector<int> asum;
vector<int> bsum;
int mx=0;

void Asum(int idx,int x)
{
    if(idx==n/2)
    {
        asum.push_back(x);
        return;
    }
    for(int i=0;i<6;i++)
    {
        Asum(idx+1,x+arr[a[idx]][i]);
    }
}
void Bsum(int idx,int x)
{
    if(idx==n/2)
    {
        bsum.push_back(x);
        return;
    }
    for(int i=0;i<6;i++)
    {
        Bsum(idx+1,x+arr[b[idx]][i]);
    }
}

void calc()
{
    int aidx,bidx;
    aidx=0;
    b.clear();
    for(int i=0;i<n;i++)
    {
        if(a[aidx]==i)
        {
            aidx++;
        }
        else
        {
            b.push_back(i);
        }
    }
    asum.clear();
    bsum.clear();
    Asum(0,0);
    Bsum(0,0);
    aidx=0;
    bidx=0;
    sort(asum.begin(),asum.end());
    sort(bsum.begin(),bsum.end());
    int cnt=0;
    while(aidx<asum.size()&&bidx<bsum.size())
    {
        
        if(asum[aidx]<=bsum[bidx])
        {
            cnt+=bidx;
            aidx++;
        }
        else
        {
            bidx++;
        }
    }
    if(aidx!=asum.size())
    {
        cnt+=(asum.size()-aidx)*(bsum.size());
    }
    if(cnt>mx)
    {
        mx=cnt;
        ans=a;
    }
}

void comb(int idx,int num)
{
    if(num==n/2)
    {
        calc();
        return;
    }
    if(idx==n)
    {
        return;
    }
    a.push_back(idx);
    comb(idx+1,num+1);
    a.pop_back();
    comb(idx+1,num);
}

vector<int> solution(vector<vector<int>> dice) {
    arr=dice;
    n=dice.size();
    vector<int> answer;
    comb(0,0);
    for(int x:ans)
    {
        answer.push_back(x+1);
    }
    return answer;
}