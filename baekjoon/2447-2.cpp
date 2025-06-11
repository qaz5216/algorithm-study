#include <iostream>

using namespace std;

int n;

void print(int i,int j,int num)
{
    if((i/num)%3==1&&(j/num)%3==1)
    {
        cout<<" ";
    }
    else
    {
        if(num/3==0)
        cout<<"*";
        else
        print(i,j,num/3);
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print(i,j,n);
        }
        cout<<"\n";
    }
    return 0;
}