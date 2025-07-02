#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string tmp,str1;
    string str2;
    cin>>tmp;
    cin>>str2;
    for(int i=0;i<tmp.size();i++)
    {
        if('0'<=tmp[i]&&tmp[i]<='9') continue;
        str1+=tmp[i];
    }
    int len=str2.size();
    for(int i=0;i<=str1.size()-len;i++)
    {
        if(str2.compare(str1.substr(i,len))==0){
            cout<<1;
            return 0;
        }
    }
    cout<<0;
    return 0;
}