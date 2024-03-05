#include <iostream>

using namespace std;
int N;
int a,b,c;
int board[2200][2200];

void cut(int x,int y,int num)
{
    for(int i=x;i<x+num;i++)
    {
        for(int j=y;j<y+num;j++)
        {
            if(board[x][y]!=board[i][j])
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        cout<<"cut("<<x+(num/3)*k<<","<<y+(num/3)*l<<","<<num/3<<")\n";
                        cut(x+(num/3)*k,y+(num/3)*l,num/3);
                    }
                }
                return;
            }
        }
    }
    if(board[x][y]==-1)
        a++;
    if(board[x][y]==0)
        b++;
    if(board[x][y]==1)
        c++;
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
    cut(0,0,N);
    cout<<a<<"\n"<<b<<"\n"<<c;
    return 0;
}