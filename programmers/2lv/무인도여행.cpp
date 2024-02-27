#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
vector<int> answer;
bool check[101][101];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int mx;
int my;
int day;
void dfs(int x,int y,vector<string> maps){
    day+=maps[x][y]-'0';
    check[x][y]=false;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(0<=xx&&xx<=mx&&0<=yy&&yy<=my){
            if(check[xx][yy]){
                if(maps[xx][yy]=='X')
                    check[xx][yy]=false;
                else
                    dfs(xx,yy,maps);
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    memset(check,true,sizeof(check));
    mx=maps.size()-1;
    my=maps[0].size()-1;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='X')
                check[i][j]=false;
            else if(check[i][j]){
                day=0;
                dfs(i,j,maps);
                answer.push_back(day);
            }
        }
    }
    if(answer.size()==0)
        answer.push_back(-1);
    sort(answer.begin(),answer.end());
    return answer;
}