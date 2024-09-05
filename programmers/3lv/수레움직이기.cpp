#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
vector<vector<int>> arr;
vector<vector<int>> rmaze;
vector<vector<int>> bmaze;
bool rcheck,bcheck;

int mn=1e9;

void dfs(pair<int,int> rcur,pair<int,int> bcur,int turn)
{
    //cout<<turn<<" --- "<<rcheck<<","<<bcheck<<" --- r = {"<<rcur.first<<","<<rcur.second<<"} b = {"<<bcur.first<<","<<bcur.second<<"} \n";
    vector<pair<int,int>> nr;
    vector<pair<int,int>> nb;
    if(rcheck&&bcheck)
    {
        //cout<<"yes"<<turn<<","<<mn<<"\n";
        mn=min(mn,turn); 
        return;
    }
    if(rcheck)
        nr.push_back(rcur);
    else{
        for(int i=0;i<4;i++)
        {
            int nx=rcur.first+dx[i];
            int ny=rcur.second+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m)
            {
                if(rmaze[nx][ny]!=5)
                {
                    nr.push_back({nx,ny});
                }
            }
        }   
    }
    if(bcheck)
        nb.push_back(bcur);
    else
    {
        for(int i=0;i<4;i++)
        {
            int nx=bcur.first+dx[i];
            int ny=bcur.second+dy[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m)
            {
                if(bmaze[nx][ny]!=5)
                {
                    nb.push_back({nx,ny});
                }
            }
        }
    }
    if(nr.size()==0||nb.size()==0)
    {
        return;
    }
    for(pair<int,int>rnext:nr)
    {
        for(pair<int,int>bnext:nb)
        {
            if(rnext==bnext)//서로 겹치는경우
                continue;
            if(rnext==bcur&&bnext==rcur)//서로 교차하는경우
                continue;
            //골 검사
            if(arr[rnext.first][rnext.second]==3)
            {
                rcheck=true;
            }
            if(arr[bnext.first][bnext.second]==4)
            {
                bcheck=true;
            }
            //벽치기
            rmaze[rcur.first][rcur.second]=5;
            bmaze[bcur.first][bcur.second]=5;
            //탐색
            dfs(rnext,bnext,turn+1);
            //벽풀기
            rmaze[rcur.first][rcur.second]=0;
            bmaze[bcur.first][bcur.second]=0;
            //골풀기
            rcheck=false;
            bcheck=false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    int answer = 0;
    arr=maze;
    rmaze=maze;
    bmaze=maze;
    pair<int,int> r;
    pair<int,int> b;
    n=maze.size();
    m=maze[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]==1)
            {
                r={i,j};
            }
            if(maze[i][j]==2)
            {
                b={i,j};
            }
        }
    }
    dfs(r,b,0);
    if(mn==1e9)
    {
        return 0;
    }
    answer=mn;
    return answer;
}