#include <iostream>

using namespace std;

int k,n;
int up[26];
bool arr[26][1001];
int down[26];
bool ans[26];
int ansrow;

int main()
{
    cin>>k;
    cin>>n;
    string res;
    cin>>res;
    for(int i=0;i<k;i++)
    {
        down[i]=res[i]-'A';
    }
    for(int i=0;i<n;i++)
    {
        string row;
        cin>>row;
        if(row[0]=='?')
        {
            ansrow=i;
            continue;
        }
        for(int j=0;j<k-1;j++)
        {
            if(row[j]=='*')
            {
                arr[j][i]=false;
            }
            else
            {
                arr[j][i]=true;
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        up[i]=i;
    }
    for(int i=0;i<ansrow;i++)
    {
        for(int j=0;j<k-1;j++)
        {
            if(arr[j][i])
            {
                swap(up[j],up[j+1]);
            }
        }
    }
    for(int i=n-1;i>ansrow;i--)
    {
        for(int j=0;j<k-1;j++)
        {
            if(arr[j][i])
            {
                swap(down[j],down[j+1]);
            }
        }
    }
    bool flag=true;
    for(int i=0;i<k;i++)
    {
        if(up[i]==down[i]) continue;
        else
        {
            if(up[i]==down[i+1]&&up[i+1]==down[i])
            {
                ans[i]=true;
                i+=1;
            }
            else
            {
                flag=false;
            }
        }
    }
    if(!flag)
    {
        for(int i=0;i<k-1;i++)
        {
            cout<<"x";
        }
    }
    else
    {
        for(int i=0;i<k-1;i++)
        {
            if(ans[i])cout<<"-";
            else cout<<"*";
        }
    }
    return 0;
}