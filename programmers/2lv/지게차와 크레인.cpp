#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
int map[53][53];
bool visit[53][53];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int remain[28];
queue<pair<int,int>> q;

void del(int a)
{
    for(int i=1;i<n+2;i++)
    {
        for(int j=1;j<m+2;j++)
        {
            if(map[i][j]==a)
            {
                map[i][j]=0;
            }
        }
    }
}

void dfs(int x,int y,int t)
{
    if(map[x][y]==0)
    {
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0<=nx&&nx<n+2&&0<=ny&&ny<m+2)
            {
                if(visit[nx][ny]) continue;
                visit[nx][ny]=true;
                dfs(nx,ny,t);
            }
        }
    }
    else if(map[x][y]==t)
    {
        q.push({x,y});
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n=storage.size();
    m=storage[0].size();
    int answer = n*m;
    memset(map,0,sizeof(map));
    for(int i=0;i<storage.size();i++)
    {
        for(int j=0;j<storage[0].size();j++)
        {
            map[i+1][j+1]=storage[i][j]-'A'+1;
            remain[storage[i][j]-'A'+1]+=1;
        }
    }
    for(string s: requests)
    {
        //print();
        if(s.size()==1)
        {
            memset(visit,false,sizeof(visit));
            int target=s[0]-'A'+1;
            dfs(0,0,target);
            remain[target]-=q.size();
            answer-=q.size();
            while(!q.empty())
            {
                pair<int,int> cur=q.front();q.pop();
                map[cur.first][cur.second]=0;
            }
        }
        else
        {
            int target=s[0]-'A'+1;
            answer-=remain[target];
            remain[target]=0;
            del(target);
        }
        
    }
    return answer;
}