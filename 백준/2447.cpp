#include <iostream>
#include <vector>

using namespace std;

int N;



void print(int i,int j,int num)
{
    if((i/num)%3==1&&(j/num)%3==1)
        cout<<" ";
    else{
        if(num/3==0)
        {
            cout<<"*";
        }
        else
            print(i,j,num/3);
    }
};

int main()
{
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            print(i,j,N);       
        }
        cout<<"\n";
    } 
    return 0;
}