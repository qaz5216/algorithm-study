#include <iostream>

using namespace std;

bool isPrime(int x)
{
    if(x<2) return false;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return false;
    }
    return true;
}

void find(int x,int num)
{
    if(num==1)
    {
        if(isPrime(x))
        {
            cout<<x<<"\n";
        }
        return;
    }
    for(int i=0;i<10;i++)
    {
        int tmp=x*10+i;
        if(isPrime(tmp))
        {
            find(tmp,num-1);
        }
    }
}

int main()
{
    int n,max;
    cin>>n;
    find(2,n);
    find(3,n);
    find(5,n);
    find(7,n);
    return 0;
}