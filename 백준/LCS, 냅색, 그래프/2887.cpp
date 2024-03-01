#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
vector<vector <int>> star;
vector<pair<double,pair<int,int>>> edge;
int p[100001];

int minx[100001];
int miny[100001];
int minz[100001];

bool cmpx(vector <int> a,vector <int>b)
{
    if(a[1]<b[1])
        return true;
    else
        return false;
}

bool cmpy(vector <int> a,vector <int>b)
{
    if(a[2]<b[2])
        return true;
    else
        return false;
}
bool cmpz(vector <int> a,vector <int>b)
{
    if(a[3]<b[3])
        return true;
    else
        return false;
}


int dist(int a,int b)
{
    int dx=star[a][1]-star[b][1];
    int dy=star[a][2]-star[b][2];
    int dz=star[a][3]-star[b][3];
    return min(min(abs(dx),abs(dy)),abs(dz));
}

int find(int x)
{
    if(x==p[x]) return x;
    return find(p[x]);
}

void myunion(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a==b) return;
    if(a>b)
        p[a]=b;
    else
        p[b]=a;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin >> x>>y>>z;
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(x);
        tmp.push_back(y);
        tmp.push_back(z);
        star.push_back(tmp);
        p[i]=i;
    }
    /*
    xyz정렬
    */
    sort(star.begin(),star.end(),cmpx);
    for(int i=1;i<n;i++)
    {
        edge.push_back({dist(i,i-1),{star[i][0],star[i-1][0]}});
    }
    sort(star.begin(),star.end(),cmpy);
    for(int i=1;i<n;i++)
    {
        edge.push_back({dist(i,i-1),{star[i][0],star[i-1][0]}});
    }
    sort(star.begin(),star.end(),cmpz);
    for(int i=1;i<n;i++)
    {
        edge.push_back({dist(i,i-1),{star[i][0],star[i-1][0]}});
    }
    sort(edge.begin(),edge.end());
    double ans=0;
    for(pair<double,pair<int,int>>e:edge)
    {
        if(find(e.second.first)!=find(e.second.second))
        {
            myunion(e.second.first,e.second.second);
            ans+=e.first;
        }
    }

    cout<<ans;

    return 0;
}