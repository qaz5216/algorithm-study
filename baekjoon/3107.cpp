#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
string answerpre[8];
string answernext[8];
int pnum;
int nnum;

string change(string str)
{
    string tmp;
    for (int i = 0; i < 4 - str.size(); i++)
    {
        tmp += '0';
    }
    tmp += str;
    return tmp;
}

int main()
{
    cin >> s;
    string tmp;
    pnum = 0;
    nnum = 0;
    bool flag = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (flag)
        {
            if (s[i] == ':')
            {
                if (s[i + 1] == ':')
                {
                    i++;
                    flag = false;
                }
                answerpre[pnum++] = change(tmp);
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }
        else
        {
            if (s[i] == ':')
            {
                answernext[nnum++] = change(tmp);
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }
    }
    if(flag){answerpre[pnum++]= change(tmp);}
    else {answernext[nnum++]= change(tmp);}
    for(int i=0;i<pnum;i++){
        cout<<answerpre[i];
        if(i!=7)cout<<':';
    }
    int cnt=pnum+nnum;
    for(int i=0;i<8-cnt;i++){
        cout<<"0000";
        if(i+pnum!=7){
            cout<<":";
        }
    }
    for(int i=0;i<nnum;i++){
        cout<<answernext[i];
        if(i!=nnum-1)cout<<':';
    }
    return 0;
}
/*
answer= 8자리

*/