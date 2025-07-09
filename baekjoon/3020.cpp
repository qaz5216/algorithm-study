#include <iostream>

using namespace std;
int suk[500001];
int jong[500001];
int ans[200001];//몇개부순거
int main()
{
    int n,h,length;
    cin>>n>>h;
    for(int i=0;i<n;i++)
    {
        cin>>length;
        if(i%2==0)
        {
            suk[length]++;
        }
        else{
            jong[length]++;
        }
    }
    int tmp;
    int cnt=1e9;
    for(int i=1;i<=h;i++)
    {
        suk[h-i+1]+=suk[h-i+2];
        jong[h-i+1]+=jong[h-i+2];
    }
    for(int i=1;i<=h;i++)
    {
        tmp=suk[h-i+1]+jong[i];
        if(cnt>tmp){
            cnt=tmp;
        }
        ans[tmp]++;
    }
    
    cout<<cnt<<' '<<ans[cnt];
    return 0;
}
/*
7       1       1       
6       1       1
5       1       1   1
4       1           1
3       1   1       1
2           1       1
1   1       1       1
*/