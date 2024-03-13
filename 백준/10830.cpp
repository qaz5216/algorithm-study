#include <iostream>

using namespace std;

#define ll long long

ll N,B;

ll arr[5][5];
ll ans[5][5];
ll tmp[5][5];
void Matrix_multi(ll x[5][5],ll y[5][5])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tmp[i][j]=0;
            for(int k=0;k<N;k++)
            {
                tmp[i][j]+=(x[i][k]*y[k][j]);
            }
            tmp[i][j]%=1000;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            x[i][j]=tmp[i][j];
        }
    }
}

int main()
{
    cin >> N >> B;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
        ans[i][i]=1;
    }
    while(B>0)
    {
        if(B%2==1)
            {
                Matrix_multi(ans,arr);
            }
            Matrix_multi(arr,arr);
            B/=2;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }   
    return 0;
}