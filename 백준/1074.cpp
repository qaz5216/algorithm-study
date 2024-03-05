#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N,r,c;
int ans=-1;
int sum=0;
void zfind(int x,int y,int num)
{
    if(ans!=-1)
        return;
    if(num==1)
    {
        bool flag=false;
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                {
                if(x+i==r&&y+j==c)
                {
                    ans=sum+i*2+j;
                    flag=true;
                    return;
                }
                }
        }
    }
    else
    {
        if(x<=r&&r<x+pow(2,num-1)&&y<=c&&c<y+pow(2,num-1))//x <= r < x+pow(2,num-1) && y <= c < y+pow(2,num-1) 
            zfind(x,y,num-1);
        else{
            sum+=pow(2,num-1)*pow(2,num-1);
        }
        if(x<=r&&r<x+pow(2,num-1)&&y+pow(2,num-1)<=c&&c<y+pow(2,num))//2사분면
            zfind(x,y+pow(2,num-1),num-1);
        else{
            sum+=pow(2,num-1)*pow(2,num-1);
        }if(x+pow(2,num-1)<=r&&r<x+pow(2,num)&&y<=c&&c<y+pow(2,num-1))
            zfind(x+pow(2,num-1),y,num-1);
        else{
            sum+=pow(2,num-1)*pow(2,num-1);
        }if(x+pow(2,num-1)<=r&&r<x+pow(2,num)&&y+pow(2,num-1)<=c&&c<y+pow(2,num))
            zfind(x+pow(2,num-1),y+pow(2,num-1),num-1);
        else{
            sum+=pow(2,num-1)*pow(2,num-1);
        }    
    }
}

int main()
{
    cin>>N>>r>>c;
    zfind(0,0,N);
    cout<<ans;
    return 0;
}