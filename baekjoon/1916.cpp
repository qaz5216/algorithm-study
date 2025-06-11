#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m,st,ed;
vector <pair<int,int>> bus[1001];
bool visit[1001];
#define MAX 1000000000
int result[1001];
priority_queue<pair<int,int>> pq;

int main()
{
    fill_n(result,1001,MAX);
    fill_n(visit,1001,false);
    cin >> n;
    cin >> m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a>>b>>c;
        bus[a].push_back({b,c}); //같은노선 두개버스
    }
    cin >> st >> ed;
    pq.push({st,0});
    result[st]=0;
    while(!pq.empty()){
        int loc=pq.top().first;
        int cost=pq.top().second;
        pq.pop();
        if(result[loc]>=cost){ // = 당연히 같을때 넣어줘야되는데 안넣었는데 왜작동됐지?
        for(int i=0;i<bus[loc].size();i++){
            if(result[bus[loc][i].first]>cost+bus[loc][i].second){
                    result[bus[loc][i].first]=cost+bus[loc][i].second;
                    pq.push({bus[loc][i].first,cost+bus[loc][i].second});
                }
        }
        }
    }
    std::cout << result[ed];
    return 0;
}