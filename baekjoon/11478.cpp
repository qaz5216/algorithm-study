#include <iostream>
#include <map>

using namespace std;

map<string,bool> m;

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=1;j+i<=s.size();j++)
        {
            string tmp=s.substr(i,j);
            m[tmp]=true;
        }
    }
    cout<<m.size();
    return 0;
}