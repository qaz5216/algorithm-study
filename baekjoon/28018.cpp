#include <iostream>

using namespace std;

int n,q;
int num[1000002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        num[s]+=1;
        //num[e]-=1;
        //각 좌석은 사용이 종료되는 시각에 곧바로 선택될 수 없다.
        num[e+1]-=1;
    }
    cin>>q;
    int tmp=0;
    for(int i=1;i<1000002;i++){
        tmp+=num[i];
        num[i]=tmp;
    }
    int t;
    for(int i=0;i<q;i++){
        cin>>t;
        cout<<num[t]<<'\n';
    }
    return 0;
}