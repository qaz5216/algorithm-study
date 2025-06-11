#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check[240000];

int main()
{
    vector<int> ans;
    for(int i=0;i<240000;i++)
    {
        if(i%3==0)
        {
            check[i]=true;
        }
    }
    for(int i=0;i<3;i++)
    {
        string ss,es;
        cin >> ss;
        cin >> es;
        int s,e;
        s=3600*stoi(ss.substr(0,2))+60*stoi(ss.substr(3,2))+stoi(ss.substr(6,2));
        e=3600*stoi(es.substr(0,2))+60*stoi(es.substr(3,2))+stoi(es.substr(6,2));
        if(e<s)
        {
            e+=3600*24;
        }
        int cnt=0;
        for(int i=s;i<=e;i++)
        {
            int h,m,s;
            h=(i/3600)%24;
            m=(i%3600)/60;
            s=i%60;
            int tmp=h*10000+m*100+s;
            if(check[tmp]) cnt++;
        }
        ans.push_back(cnt);
    }
    for(int answer:ans)
    {
        cout<<answer<<"\n";
    }
    return 0;
}