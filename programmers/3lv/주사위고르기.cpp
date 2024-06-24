#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> arr;
int A[5],B[5];
int ans[5];
int maxwinnum=0;
vector<int> Asum,Bsum;


void initsum(int idx,int sum,bool op)
{
    if(idx==N/2)
    {
        if(op)
        Asum.push_back(sum);
        else
        Bsum.push_back(sum);
        return;
    }
    for(int i=0;i<6;i++)
    {
        if(op)
        initsum(idx+1,sum+arr[A[idx]][i],op);
        else
        initsum(idx+1,sum+arr[B[idx]][i],op);
    }
}

void calc()
{
    Asum.clear();
    Bsum.clear();
    initsum(0,0,true);
    initsum(0,0,false);
    sort(Asum.begin(),Asum.end());
    sort(Bsum.begin(),Bsum.end());
    int aidx=0;
    int bidx=0;
    int winnum=0;
    while(aidx<Asum.size()&&bidx<Bsum.size())
    {
        if(Asum[aidx]>Bsum[bidx])
        {
            bidx+=1;
        }
        else
        {
            winnum+=bidx;
            aidx+=1;
        }
    }
    if (bidx==Bsum.size())
    {
        winnum+=bidx*(Asum.size()-aidx);
    }
    if(winnum>maxwinnum)
    {
        maxwinnum=winnum;
        for(int i=0;i<N/2;i++)
        {
            ans[i]=A[i]+1;
        }
    }
}

void comb(int idx)
{
    if(idx==N/2)
    {
        int aidx=0;
        int bidx=0;
        for(int i=0;i<N;i++)
        {
            if(A[aidx]==i&&aidx<N/2){
                aidx++;
            }
            else
            {
                B[bidx]=i;
                bidx++;
            }
        }
        calc();
    }
    if(idx==0)
    {
        for(int i=0;i<N;i++)
        {
            A[idx]=i;
            comb(idx+1);
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            if(A[idx-1]<i){
            A[idx]=i;
            comb(idx+1);
            }
        }
    }
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    arr=dice;
    N=dice.size();
    comb(0);
    for(int i=0;i<N/2;i++)
    {
        answer.push_back(ans[i]);
    }
    return answer;
}