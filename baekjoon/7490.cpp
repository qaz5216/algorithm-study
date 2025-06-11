#include <iostream>
#include <string>
using namespace std;

string ss;

void calc(int n)
{
    int sum=0;
    int idx=n*2-1;
    bool op=true;
    string tmp;
    for(int i=0;i<n*2-1;i++)
    {
        if(ss[i]<'0'||'9'<ss[i])
        {
            if(ss[i]!=' ')
            {
                if(op)
                {
                    sum+=stoi(tmp);
                }
                else
                {
                    sum-=stoi(tmp);
                }
                tmp.resize(0);
                if(ss[i]=='+')
                {
                    op=true;
                }
                else
                {
                    op=false;
                }
            }
        }
        else
        {
            tmp.push_back(ss[i]);
        }
    }
    if(op)
    {
        sum+=stoi(tmp);
    }
    else
    {
        sum-=stoi(tmp);
    }
    if(sum==0)
    {
        cout<<ss<<"\n";
    }
}

void solve(int n,int num,int idx)
{
    if(n==num)
    {
        ss[idx]=num+'0';
        calc(n);
        return ;
    }
    ss[idx]=num+'0';
    ss[idx+1]=' ';
    solve(n,num+1,idx+2);
    ss[idx+1]='+';
    solve(n,num+1,idx+2);
    ss[idx+1]='-';
    solve(n,num+1,idx+2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ss.resize(n*2-1);
        solve(n,1,0);
        cout<<"\n";
    }
    return 0;
}
