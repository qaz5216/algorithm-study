#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

bool visit[101][101];

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    memset(visit,0,sizeof(visit));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visit[i][j]!=0||picture[i][j]==0) continue;
            visit[i][j]=true;
            answer[0]++;
            queue<pair<int,int>> q;
            q.push(make_pair(i,j));
            int size=1;
            while(!q.empty()){
                pair<int,int> tmp=q.front();q.pop();
                for(int d=0; d<4;d++){
                    int nx = tmp.first+dx[d];
                    int ny = tmp.second+dy[d];
                    if(nx>=0 && ny>=0 &&nx<m && ny<n){
                        if(!visit[nx][ny]&&picture[nx][ny]==picture[i][j]){
                            visit[nx][ny]=true;
                            size++;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
            answer[1]=max(answer[1],size);
        }
    }
    return answer;
}