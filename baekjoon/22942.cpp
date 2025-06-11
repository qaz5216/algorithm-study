#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector<pair<int,int>> v;

int main()
{
    int n;
    bool flag=true;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,r;
        cin>>x>>r;
        v.push_back({x-r,x+r});
    }
    sort(v.begin(),v.end());
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        while (!s.empty()&&s.top()<v[i].first)
        {
            s.pop();
        }
        if(!s.empty()&&s.top()>=v[i].first&&s.top()<=v[i].second)
        {
            flag=false;
            break;
        }
        s.push(v[i].second);
    }
    if(flag)cout<<"YES";
    else cout<<"NO";
    return 0;
}