#include <iostream>
#include <vector>
using namespace std;

int N,Q;
vector<int> edge[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    cin >> Q;
    for(int i=0;i<Q;i++){
        int a,b;
        cin >> a >>b;
        if(a==1)
        {
            //b=단절점?(리프노드가 아니냐?)
            if(edge[b].size()>1)
            {
                cout<<"yes\n";
            }
            else
            {
                cout<<"no\n";
            }
        }
        else
        {
       
            cout<<"yes\n";
         
        }
    }
    return 0;
}