#include <iostream>

using namespace std;

int jm,sm;//준현이돈,성민이돈
int j=0,s=0;//주식보유갯수 준현,성민

int arr[14];

int main()
{
    cin>>jm;
    sm=jm;
    for(int i=0;i<14;i++)
    {
        cin>>arr[i];
    }
    int n=jm/arr[0];
    j+=n;
    jm-=n*arr[0];   //준현이 0일차 매수

    int up=0,down=0; //연속 상승,하락 일차
    for(int i=1;i<14;i++)
    {
        n=jm/arr[i];
        j+=n;
        jm-=n*arr[i]; //준현이 i일차 매수
        if(arr[i]>arr[i-1])
        {
            down=0;
            up++;
        }
        else if(arr[i]<arr[i-1])
        {
            up=0;
            down++;
        }
        else
        {
            up=0;
            down=0;
        }
        if(up>=3)//3일연속 상승
        {   //성민이 매도
            sm+=s*arr[i];
            s=0;

        }
        else if(down>=3)//3일연속 하락
        {   //성민이 매수
            n=sm/arr[i];
            sm-=n*arr[i];
            s+=n;
        }
    }
    jm=jm+j*arr[13];//준현이돈
    sm=sm+s*arr[13];//성민이돈
    if(jm==sm)
    {
        cout<<"SAMESAME";
    }
    else if(jm>sm)
    {
        cout<<"BNP";
    }
    else{
        cout<<"TIMING";
    }
    return 0;
}