#include <iostream>
#include <queue>
#include <queue>

using namespace std;

int n;
int ans=0;

int main()
{
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> sq;
    priority_queue<int,vector<int>,greater<int>> eq; 
    for(int i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sq.push({b,c});
    }
    while(!sq.empty())
    {
        int s=sq.top().first;
        int e=sq.top().second;
        sq.pop();
        while(true)
        {
            if(eq.empty()||eq.top()>s){
                break;
            }
            else{
                eq.pop();
            }
        }
        eq.push(e);
        ans=max(ans,(int)eq.size());
    }
    cout<<ans;
    return 0;
}