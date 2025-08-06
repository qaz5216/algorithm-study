#include <iostream>
using namespace std;
int edge[100001][2];
int cnt;
int depth;


void dfs2(int cur){
    if(edge[cur][1]!=0){
        depth++;
        dfs2(edge[cur][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(b==-1)b=0;
        if(c==-1)c=0;
        edge[a][0]=b;
        edge[a][1]=c;
    }
    cnt=(n-1)*2;
    depth=0;
    dfs2(1);
    cout<<cnt-depth;
    return 0;
}