#include <iostream>
#include <vector>
using namespace std;

int N,M;
int arr[100001];
int Mxseg[400005];
int Mnseg[400005];
vector<pair<int,int>>ans;
int initMxseg(int node,int start,int end)
{
    if(start==end) return Mxseg[node]=arr[start];
    int mid=(start+end)/2;
    return Mxseg[node]=max(initMxseg(node*2,start,mid),initMxseg(node*2+1,mid+1,end));
}

int initMnseg(int node,int start,int end)
{
    if(start==end) return Mnseg[node]=arr[start];
    int mid=(start+end)/2;
    return Mnseg[node]=min(initMnseg(node*2,start,mid),initMnseg(node*2+1,mid+1,end));
}

pair<int,int> query(int node,int start,int end,int left,int right)
{
    if(end<left||right<start) return {1e9,0};
    if(left<=start&&end<=right) return {Mnseg[node],Mxseg[node]};
    int mid=(start+end)/2;
    pair<int,int> l=query(node*2,start,mid,left,right);
    pair<int,int> r=query(node*2+1,mid+1,end,left,right);
    return {min(l.first,r.first),max(l.second,r.second)};
}

int main()
{
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    //init
    initMxseg(1,0,N-1);
    initMnseg(1,0,N-1);
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);
        ans.push_back(query(1,0,N-1,a-1,b-1));
    }
    for(pair<int,int>answer:ans)
    {
        cout<<answer.first<<" "<<answer.second<<"\n";
    }
    return 0;
}