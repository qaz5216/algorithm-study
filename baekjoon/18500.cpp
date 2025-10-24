#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool board[102][102];
bool visit[102][102];
int group[102][102];
int r,c,n;

void dfs(int x,int y,int g){
    group[x][y]=g;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(board[nx][ny]&&group[nx][ny]==0){
            dfs(nx,ny,g);
        }
    }
}
// void downdfs(int x,int y){//내려갈 거리찾기
//     //y 1만날떄까지 내리던가 다른 클러스트 찾기
// }

// void down(int x,int y){
//     downflag=true;
//     movec.clear();
//     memset(visit,false,sizeof(visit));

// }

void printboard(){
    for(int i=r;i>0;i--){
        for(int j=1;j<=c;j++){
            if(board[i][j])cout<<'x';
            else cout<<'.';
        }cout<<'\n';
    }
}
void printgroup(){
    for(int i=r;i>0;i--){
        for(int j=1;j<=c;j++){
            cout<<group[i][j];
        }cout<<'\n';
    }
}

void changegroup(int target,int to){
    for(int i=r;i>0;i--){
        for(int j=1;j<=c;j++){
            if(group[i][j]==target)group[i][j]=to;
        }
    }
}

int down(int target){//target group
    int result;
    for(int i=r;i>0;i--){
        for(int j=1;j<=c;j++){
            if(group[i][j]==target){
                {
                    int n=0;
                    while(true){
                        if(i-n==1||(group[i-n][j]!=target && group[i-n][j]!=0))
                        {
                            break;
                        }
                        n++;
                    }
                }
            }
        }
    }
    return result;
}

void ltor(int y){//왼쪽에서 오른쪽으로 부수기
    for(int i=1;i<=c;i++){
        if(board[y][i]){
            board[y][i]=false;
            break;
        }
    }
}
void rtol(int y){
    for(int i=c;i>0;i--){
        if(board[y][i]){
            board[y][i]=false;
            break;
        }
    }
}

int main(){
    cin>>r>>c;
    for(int i=r;i>0;i--){
        for(int j=1;j<=c;j++){
            char c;
            cin>>c;
            if(c=='x')board[i][j]=true;
        }
    }
    cin>>n;
    bool flag=true;
    while(n--){
        //부수기
        int target;
        cin>>target;
        if(flag) ltor(target);
        else rtol(target);
        flag!=flag;
        //보드확인
        memset(group,0,sizeof(group));
        
        printgroup();
        int num=1;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(!board[i][j]||group[i][j]!=0)continue;
                dfs(i,j,num);
                num++;
            }
        }
        printgroup();
    }
    //printboard();
    return 0;
}