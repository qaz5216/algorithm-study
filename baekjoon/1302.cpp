#include <iostream>
#include <map>

using namespace std;

map <string,int> m;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        m[s]++;
    }
    int num=0;
    for(auto v:m)
    {
        if(v.second>num)
        {
            s=v.first;
            num=v.second;
        }
        else if(v.second==num&&v.first<s)
        {
            s=v.first;
        }
    }
    cout<<s;
    return 0;
}