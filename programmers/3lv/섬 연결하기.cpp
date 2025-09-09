#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int check[101];
int edge[101][101];

int getParent(int node){
	if(check[node]==node) return node;
	return getParent(check[node]);
}

void unionParent(int node1,int node2)
{
    node1=getParent(node1);
    node2=getParent(node2);
    if(node1<node2) check[node2]=node1;
    else    check[node1]=node2;
}

bool isUnion(int node1,int node2)
{
    node1=getParent(node1);
    node2=getParent(node2);
    if(node1==node2) return true;
    else return false;
}

bool comp(vector<int> A,vector<int> B)
{
    return A[2]<B[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        check[i]=i;           
    }
    sort(costs.begin(),costs.end(),comp);
    for(vector<int> cost:costs)
    {
        if(!isUnion(cost[0],cost[1]))
        {
            answer+=cost[2];
            unionParent(cost[0],cost[1]);
        }
    }
    return answer;
}