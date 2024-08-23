#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    cin>>m;
    sort(v.begin(),v.end());
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        int l=0,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(v[mid]<=x)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        int upper=l;
        l=0;r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(v[mid]<x)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        int lower=l;
        cout<<upper-lower<<" ";
    }
    return 0;
}


/*  map solution

#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int,int> num;
vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        ans.push_back(num[x]);
    }
    for(int x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}
*/
