#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

char board[31][30002];
set<int> dp[31];
int R,C,N;
stack<pair<int,int>> check[31];

void down(int x,int y,int start)
{
    int tmp=*(dp[x].upper_bound(y));
    if(board[x][tmp]=='X'){
        board[x][tmp-1]='O';
        dp[x].insert(tmp-1);
        dp[x].erase(tmp);
    }
    else{   //왼쪽이 비었으면
        if(x>1&&board[x-1][tmp]=='.'&&board[x-1][tmp-1]=='.'){
            check[start].push(make_pair(x,tmp-1));
            down(x-1,tmp,start);
        }    //오른쪽이 비었으면
        else if(x<C&&board[x+1][tmp]=='.'&&board[x+1][tmp-1]=='.'){
            check[start].push(make_pair(x,tmp-1));
            down(x+1,tmp,start);
        }    //둘다 찼으면
        else{
            board[x][tmp-1]='O';
            dp[x].insert(tmp-1);
            dp[x].erase(tmp);
        }
    }

}

void printarr()
{
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cout<<board[j][i];
        }
    cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;
    for(int i=1;i<=R;i++)
    {
        for(int j=1;j<=C;j++)
        {
            cin>>board[j][i];
            if(board[j][i]=='X')
            {
                dp[j].insert(i);
            }
        }
    }
    for(int j=1;j<=C;j++)
    {
        board[j][R+1]='X';
        dp[j].insert(R+1);
    }
    cin>>N;
    while(N--)
    {
        int x;
        cin >> x;
        int cx,cy;
        while (!check[x].empty())
        {
            cx=check[x].top().first;
            cy=check[x].top().second;
            if(board[cx][cy]!='.')
            {
                check[x].pop();
            }
            else{
                break;
            }
        }
        if(check[x].empty()){
            down(x,1,x);
        }
        else
        {
            down(cx,cy,x);
        }  
    }
    printarr();
    return 0;
}