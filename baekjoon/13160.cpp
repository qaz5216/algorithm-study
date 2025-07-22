#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

//10 0000 0000
int n;
pair<int,int> arr[300001];
int tmp[600001];
unordered_map<int,int> changer;
int num[600002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    int s,e;
    for(int i=0;i<n;i++){
        cin>>s>>e;
        tmp[2*i]=s;
        tmp[2*i+1]=e;
        arr[i]={s,e};
    }
    sort(tmp,tmp+n*2);
    int idx=1;
    int prev=tmp[0];
    changer[tmp[0]]=1;
    for(int i=1;i<2*n;i++){
        if(prev!=tmp[i]){
            idx++;
            changer[tmp[i]]=idx;
        }
        prev=tmp[i];
    }
    for(int i=0;i<n;i++){
        arr[i].first=changer[arr[i].first];
        arr[i].second=changer[arr[i].second];
        num[arr[i].first]+=1;
        num[arr[i].second+1]-=1;
    }
    pair<int,int> mx;//first=cnt,second=idx;
    mx={0,0};
    int cnt=0;
    for(int i=1;i<=idx;i++){
        cnt+=num[i];
        num[i]=cnt;
        mx=cnt>mx.first? make_pair(cnt,i):mx;
    }
    cout<<mx.first<<'\n';
    for(int i=0;i<n;i++){
        if(arr[i].first<=mx.second&&mx.second<=arr[i].second)
        {
            cout<<i+1<<' ';
        }
    }
    return 0;
}