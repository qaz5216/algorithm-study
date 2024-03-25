#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T;

int main()
{
    cin >> T;
    while(T--)
    {
        int N;
        bool rootcheck[10001];
        cin >> N;
        int edge[10001];
        for(int i=1;i<N+1;i++)
        {
            rootcheck[i]=true;
        }
        for(int i=0;i<N-1;i++)
        {
            int a,b;
            cin>>a>>b;
            rootcheck[b]=false;
            edge[b]=a;
        }
        int root=1;
        for(int i=1;i<N+1;i++)
        {
            if(rootcheck[i])
            {
                root=i;
            }
        }
        int x,y;
        cin >> x >>y;
        queue<int> q;
        bool find[10001];
        for(int i=1;i<N+1;i++)
        {
            find[i]=false;
        }
        q.push(x);
        q.push(y);
        int par=-1;
        while(!q.empty())
        {
            int cur=q.front();q.pop();
            if(find[cur]==true)
            {
                par=cur;
                break;   
            }
            else{
                find[cur]=true;
                if(cur!=root)
                    q.push(edge[cur]);
            }
        }
        cout<<par<<"\n";
    }
    return 0;
}